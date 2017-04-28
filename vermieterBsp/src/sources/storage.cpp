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
	int id = 0;
	std::cout<<"\ncurrently stored persons:\n"<<std::endl;
	for (auto const &pers : persons) {
		std::cout<<std::setfill('-')<<std::setw(80)<<std::endl;
		std::cout<<"\nperson ID "<<id++<<std::endl;
		pers->printToScreen();
		std::cout<<pers.use_count()<<std::endl;
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

	switch (type) {
		case 1:
			persons.push_back(std::make_shared<Vermieter>());
			persons.back()->setProperties();
			break;
		case 2:
			persons.push_back(std::make_shared<Mieter>());
			persons.back()->setProperties();
			break;
		case 3:
			return;
		default:
			break;
	}
	return;
}

void Storage::addFlat() {

	std::vector<int> opt = {1,2,3};
	int type = checkInt("\nenter Mietobject type:\n\t(1) Haus\n\t(2) Whg\n\t(3) go back\n", &opt);

	switch (type) {
		case 1:
			flats.push_back(std::make_shared<Haus>());
			flats.back()->setProperties();
			break;
		case 2:
			flats.push_back(std::make_shared<Whg>());
			flats.back()->setProperties();
			break;
		case 3:
			return;
		default:
			break;
	}
	return;
}

int Storage::checkInt(const std::string &text, std::vector<int> *opt = nullptr ) {
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

unsigned int Storage::checkUInt(const std::string &text) {
	unsigned int uintVal;
	std::cout<<text<<std::endl;
	while(!(std::cin >> uintVal)) {
		std::cerr<<" invalid choice, unsigned integer value required try again\n"<<text<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
			csv<<persons.at(i)->csvLine()<< endrow;;
		}

		std::cout<<"\n"<<i<<" person tuples successfully written into file:\t"<<filename<<std::endl;

		for (i = 0; i< flats.size(); ++i)
			csv<<flats.at(i)->csvLine()<< endrow;;

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

		while (std::getline(infile, aux, ';')) {
			type = stoi(aux);
			std::getline(infile, aux);
			values = split(aux,";");
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

std::vector<unsigned int> Storage::splitUInt(const std::string& str, const std::string& delim) {
	std::vector<unsigned int> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(std::stoul(token));
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());

    return tokens;
}

void Storage::proceedInTime() {
	double months = checkDouble("\nenter number of months to wait\n");

	for (auto &flat : flats)
        flat-> updateProfit(months);
}
