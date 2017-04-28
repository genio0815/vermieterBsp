/*
 * storage.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: alexander.bindeus
 */

#include "../includes/Storage.h"
#include "../includes/CSVFile.h"
#include <algorithm>

// initialize static vectors
std::vector<std::shared_ptr<Person>> Storage::persons;
std::vector<std::shared_ptr<MietObject>> Storage::flats;

Storage::Storage() {}

void Storage::listPersons() {
	std::cout<<"\ncurrently stored persons:\n"<<std::endl;
	for (auto const &pers : persons) {
		std::cout<<std::setfill('-')<<std::setw(80)<<std::endl;
		std::cout<<"\nperson ID "<<pers->getId()<<std::endl;
		pers->printToScreen();
		if (pers->getType())
			std::cout<<"owns "<<pers.use_count()-1<<" flat(s)"<<std::endl;
		else
			// now limited to just 1 !!!
			std::cout<<"rents "<<pers.use_count()-1<<" flat(s)"<<std::endl;
	}
}

void Storage::listFlats() {
	int id = 0;
	std::cout<<"\ncurrently stored flats:\n"<<std::endl;
	for (auto const &flat : flats) {
		std::cout<<std::setfill('-')<<std::setw(80)<<std::endl;
		std::cout<<"\nflat ID "<<id++<<std::endl;
		flat->printToScreen();
	}
}

void Storage::addPerson() {

	std::vector<int> opt = {1,2,3};
	int type = checkInt("\nenter person type:\n\t(1) Vermieter\n\t(2) Mieter\n\t(3) go back\n", &opt);

    // ignoring def. case
	switch (type) {
		case 1:
			persons.push_back(std::make_shared<Vermieter>());
			break;
		case 2:
			persons.push_back(std::make_shared<Mieter>());
			break;
		case 3:
			return;
	}
	persons.back()->setId(persons.size()-1);
    persons.back()->setProperties();
	return;
}

void Storage::addFlat() {

	std::vector<int> opt = {1,2,3};
	int type = checkInt("\nenter Mietobject type:\n\t(1) Haus\n\t(2) Whg\n\t(3) go back\n", &opt);

    // ignoring def. case
	switch (type) {
		case 1:
			flats.push_back(std::make_shared<Haus>());
			break;
		case 2:
			flats.push_back(std::make_shared<Whg>());
			break;
		case 3:
			return;
	}
    flats.back()->setProperties();
	return;
}

int Storage::checkInt(const std::string &text, std::vector<int> *opt = nullptr) {
	int intVal;
	std::cout<<text<<std::endl;

	if (opt != nullptr) {
		while(!(std::cin >> intVal) || (std::find(opt->begin(), opt->end(), intVal) == opt->end())) {
			std::cerr<<"\ninvalid choice, please select of the integers\n"<<text<<std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} else {
		while(!(std::cin >> intVal)) {
			std::cerr<<"invalid choice, integer value required try again\n"<<text<<std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return intVal;
}

std::string Storage::checkString(const std::string &text) {
	std::string stringVal;
	std::cout<<text<<std::endl;
	std::getline(std::cin, stringVal);
	return stringVal;
}

bool Storage::checkBool(const std::string &text) {
	bool boolVal;
	std::cout<<text<<std::endl;
	while(!(std::cin >> boolVal)) {
		std::cerr<<"invalid choice, bool value required try again\n"<<text<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return boolVal;
}

double Storage::checkDouble(const std::string &text) {
	double doubleVal;
	std::cout<<text<<std::endl;
	while(!(std::cin >> doubleVal)) {
		std::cerr<<"invalid choice, double value required try again\n"<<text<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return doubleVal;
}

unsigned int Storage::checkUInt(const std::string &text, std::vector<unsigned int> *opt = nullptr) {

	unsigned int uintVal;
	std::cout<<text<<std::endl;

    if (opt != nullptr) {
        while(!(std::cin >> uintVal) || (std::find(opt->begin(), opt->end(), uintVal) == opt->end())) {
            std::cout<<"\ninvalid choice, please select of the following unsigned integers:"<<std::endl;
            for (auto &o : *opt) std::cout<<o<<' ';
            std::cout<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } else {
        while(!(std::cin >> uintVal)) {
            std::cerr<<"invalid choice, unsigned integer value required try again\n"<<text<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return uintVal;
}

void Storage::writeCSV(const std::string &filename) {
	unsigned int i;
	try {
		csvfile csv(filename);

		for (i = 0; i< persons.size(); ++i) {
			persons.at(i)->setId(i);
			std::cout<<persons.at(i)->csvLine()<<std::endl;
			csv<<persons.at(i)->csvLine()<< endrow;;
		}

		std::cout<<"\n"<<i<<" person tuples successfully written into file:\t"<<filename<<std::endl;

		for (i = 0; i< flats.size(); ++i) {
            std::cout<<flats.at(i)->csvLine()<<std::endl;
            csv << flats.at(i)->csvLine() << endrow;;
        }

		std::cout<<"\n"<<i<<" flat tuples successfully written into file:\t"<<filename<<std::endl;
		}
	catch (const std::exception& ex) {
		std::cout << "Exception was thrown: " << ex.what() << std::endl;
	}
}

void Storage::readCSV(const std::string &filename) {
	try {

		int type;
		std::vector<std::string> values;
		std::string aux;
		std::ifstream infile;
		infile.open(filename);

		while (std::getline(infile, aux, ',')) {
			type = stoi(aux);
			std::getline(infile, aux);
			values = split(aux,",");
			switch (type) {
				case 1:
					persons.push_back(std::make_unique<Mieter>());
					persons.back()->readProperties(&values);
					break;
				case 2:
					persons.push_back(std::make_unique<Vermieter>());
					persons.back()->readProperties(&values);
					break;
				case 3:
					flats.push_back(std::make_unique<Haus>());
					flats.back()->readProperties(&values);
					break;
				case 4:
					flats.push_back(std::make_unique<Whg>());
					flats.back()->readProperties(&values);
					break;
			}
		}
		infile.close();
		std::cout<<"\nentries successfully read from file:\t"<<filename<<std::endl;
		}
	catch (const std::exception& ex) {
		std::cout << "Exception was thrown: " << ex.what() << std::endl;
	}
}

std::vector<std::string> Storage::split(const std::string& str, const std::string& delim) {
	std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());

    for (std::string bla : tokens) {
    	std::cout<<bla<<std::endl;
    }
    return tokens;
}

void Storage::changeOwner() {

    if (flats.size() == 0 || persons.size() == 0) {
        std::cout<<"no flats or persons entered yet...returning"<<std::endl;
        return;
    }

    unsigned int i, k;
    std::vector<unsigned int> vermieterIds, flatIds;

    for (i = 0; i < persons.size(); ++i) {
        if (persons.at(i)->getType()) {  //Vermieter true
            vermieterIds.push_back(i);//(flats.at(i)->getOwnerPtr()->getId());
        }
    }

    if (vermieterIds.size() == 0) {
		std::cout<<"no renters present - returning"<<std::endl;
		return;
	}

    for (i =0; i < flats.size(); ++i) {
        flatIds.push_back(i);
    }

    std::cout<<"available flats:"<<std::endl;
    for (i = 0; i < flatIds.size(); ++i)
    	std::cout<<flatIds.at(i)<<'\t'<<flats.at(i)->getAddress()<<std::endl;

    i = checkUInt("enter ID of flat to adopt:", &flatIds);

    std::cout<<"available Vermieter:"<<std::endl;
    for (k = 0; k < vermieterIds.size(); ++k)
	    std::cout<<vermieterIds.at(k)<<'\t'<<persons.at(k)->getName()<<std::endl;

    k = checkUInt("select available Vermieter:", &vermieterIds);

    std::cout<<"changing owner from "<<(flats.at(i)->getOwnerPtr() == nullptr ? "NONE" : flats.at(i)->getOwnerPtr()->getName())<<" to "
    		<<persons.at(k)->getName()<<std::endl;
    flats.at(i)->setOwnerPtr(std::static_pointer_cast<Vermieter> (persons.at(k)));
}

void Storage::changeRenter() {

    if (flats.size() == 0 || persons.size() == 0) {
        std::cout<<"no flats or persons entered yet...returning"<<std::endl;
        return;
    }

    unsigned int i, k;
    std::vector<unsigned int> renterIds, flatIds;

    for (i = 0; i < persons.size(); ++i) {
        if (!persons.at(i)->getType()) {  //Mieter false
            renterIds.push_back(i);
        }
    }

    if (renterIds.size() == 0) {
    	std::cout<<"no renters present - returning"<<std::endl;
    	return;
    }

    // restrict Mieter to rent just one flat
    std::cout<<"available flats:"<<std::endl;
    for (i = 0; i < flatIds.size(); ++i) {
    	if(flats.at(i)->getRenterPtr() != nullptr) {
    		flatIds.push_back(i);
    		std::cout<<flatIds.at(i)<<'\t'<<flats.at(i)->getAddress()<<"\trented by\t"<<flats.at(i)->getRenterPtr()->getName()<< std::endl;
    	}
    }

    i = checkUInt("enter ID of flat to adopt:", &flatIds);
    std::cout<<"available Mieter:"<<std::endl;
    for (k = 0; k < renterIds.size(); ++k)
   	    std::cout<<renterIds.at(k)<<'\t'<<persons.at(k)->getName()<<std::endl;

    k = checkUInt("select available Mieter:", &renterIds);

    //2804: added delete option
    std::string token = Storage::checkString("to remove Mieter from flat enter REMOVE");
    if (token.compare("REMOVE") == 0 ){
    	std::cout<<"removing Mieter "<<persons.at(k)->getName()<<" from storage"<<std::endl;
    	persons.erase(persons.begin()+k);
    }

    std::cout<<"changing renter from "<<(flats.at(i)->getRenterPtr() == nullptr ? "NONE" : flats.at(i)->getRenterPtr()->getName())
    		<<" to " <<persons.at(k)->getName()<<std::endl;
    flats.at(i)->setRenterPtr(std::static_pointer_cast<Mieter> (persons.at(k)));
}

void Storage::proceedInTime() {
	double months = checkDouble("\nenter number of months to wait\n");
	for (auto &flat : flats)
        flat-> updateProfit(months);
}
