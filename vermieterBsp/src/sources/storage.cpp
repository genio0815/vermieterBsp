/*
 * storage.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: alexander.bindeus
 */

#include "../includes/Storage.h"
#include <vector>

// initialize static vectors
std::vector<Person> Storage::persons;
std::vector<MietObject> Storage::flats;
Storage::Storage() {}

void Storage::listPersons() {
	for (Person pers : persons) {
		std::cout<<pers.getAge()<<std::endl;
	}
}

void Storage::listFlats() {
	for (MietObject flat : flats) {
		std::cout<<flat.getAdress()<<std::endl;
	}
}

void Storage::addPerson(Person addMe) {
	this->persons.push_back(addMe);
}

void Storage::addFlat(MietObject addMe) {
	this->flats.push_back(addMe);
}
