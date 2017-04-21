/*
 * storage.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: alexander.bindeus
 */

#include "../includes/Storage.h"
#include <algorithm>

// initialize static vectors
std::vector<std::unique_ptr<Person>> Storage::persons;
std::vector<std::unique_ptr<MietObject>> Storage::flats;
Storage::Storage() {}

void Storage::listPersons() {
	int id = 0;

	for (auto const &pers : persons) {
		std::cout<<std::setfill('-')<<std::setw(80)<<std::endl;
		std::cout<<"\nperson ID "<<id++<<std::endl;
		pers->printToScreen();
	}
}

void Storage::listFlats() {
	int id = 0;

	for (auto const &flat : flats) {
		std::cout<<std::setfill('-')<<std::setw(80)<<std::endl;
		std::cout<<"\nflat ID "<<id++<<std::endl;
		flat->printToScreen();
	}
}

void Storage::addPerson() {

	int age;
	std::string name;

	std::vector<int> opt = {1,2,3};
	int type = checkInt("\nenter person type:\n\t(1) Vermieter\n\t(2) Mieter\n\t(3) go back\n", &opt);

	switch (type) {
		case 1:
			name = checkString("\nenter Vermieter's name ");
			age = checkInt("enter " + name + "'s age", nullptr);

			persons.emplace_back(new Vermieter(name, age));
			dynamic_cast<Vermieter*>(persons.at(persons.size()-1).get())->setProperties();
			break;
		case 2:
			name = checkString("\nenter Mieter's name ");
			age = checkInt("enter " + name + "'s age",nullptr);

			persons.emplace_back(new Mieter(name, age));
			dynamic_cast<Mieter*>(persons.at(persons.size()-1).get())->setProperties();
			break;
		case 3:
			return;

		default:
			addPerson();
	}
}

void Storage::addFlat() {
	std::string address;
	std::vector<int> opt = {1,2,3};

	int type = checkInt("\nenter Mietobject type:\n\t(1) Haus\n\t(2) Whg\n\t(3) go back\n", &opt);

	switch (type) {
		case 1:
			flats.push_back(std::make_unique<Haus>());
			flats.back()->setProperties();
			break;
		case 2:
			flats.push_back(std::make_unique<Whg>());
			flats.back()->setProperties();
			break;
		case 3:
			return;
		default:
			addFlat();
	}
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
	return intVal;
}

std::string Storage::checkString(const std::string &text) {
	std::string stringVal;
	std::cout<<text<<std::endl;
	while(!(std::cin >> stringVal)) {
		std::cerr<<"invalid choice, string value required try again\n"<<text<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
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
	return doubleVal;
}

unsigned int Storage::checkUInt(const std::string &text) {
	unsigned int uintVal;
	std::cout<<text<<std::endl;
	while(!(std::cin >> uintVal)) {
		std::cerr<<"invalid choice, double value required try again\n"<<text<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return uintVal;
}
