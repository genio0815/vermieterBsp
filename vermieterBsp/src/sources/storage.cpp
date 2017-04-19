/*
 * storage.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: alexander.bindeus
 */

#include "../includes/Storage.h"

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
	for (auto const &flat : flats) {
		std::cout<<flat->getAdress()<<std::endl;
	}
}

void Storage::addPerson() {

	int type, age;
	std::string name;

	std::cout<<"\nenter person type:\n\t(1) Vermieter\n\t(2) Mieter\n\t(3) go back\n"<<std::endl;
	while(!(std::cin >> type)) {
		std::cerr<<"invalid choice, try again\n"<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	switch (type) {
		case 1:
			std::cout<<"\nenter Vermieter's name ";
			std::getline(std::cin,name);
			age = checkInt("enter " + name + "'s age");

			persons.emplace_back(new Vermieter(name, age));
			dynamic_cast<Vermieter*>(persons.at(persons.size()-1).get())->setProperties();
			break;
		case 2:
			std::cout<<"\nenter Mieter's name ";
			std::getline(std::cin,name);
			age = checkInt("enter " + name + "'s age");

			persons.emplace_back(new Mieter(name, age));
			dynamic_cast<Mieter*>(persons.at(persons.size()-1).get())->setProperties();
			break;
		case 3:
			return;

		default:
			//std::cerr<<"invalid choice"<<std::endl;
			addPerson();
	}
}

int Storage::checkInt(const std::string &text) {
	int intVal;
	std::cout<<text<<std::endl;
	while(!(std::cin >> intVal)) {
		std::cerr<<"invalid choice, integer value required try again\n"<<text<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return intVal;
}

double Storage::checkDouble(const std::string &text) {
	double doubleVal;
	std::cout<<text<<std::endl;
	while(!(std::cin >> doubleVal)) {
		std::cerr<<"invalid choice, integer value required try again\n"<<text<<std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return doubleVal;
}


void Storage::addFlat() {
	//this->flats.push_back(addMe);
}


