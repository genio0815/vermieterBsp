/*
 * vermieter.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include <algorithm>
#include <string>
#include <vector>
#include "../includes/Vermieter.h"
#include "../includes/Storage.h"

Vermieter::Vermieter() : Person() {
	income = 0.0;
}

void Vermieter::updateBalance(double income){
	this->income += income;
}
void Vermieter::printToScreen(){
	std::cout<<"\nVermieter\t";
	Person::printToScreen();
	std::cout<<"income:\t"<<income<<std::endl;
}

void Vermieter::setProperties() {
	std::string token;
	unsigned int i;

	Person::setProperties();

	// that's tricky...
	if (Storage::persons.back()->getId() == this->id) return;

	if (Storage::flats.size() > 0) {
		token = Storage::checkString("to assign Owner to existing flat enter YES\notherwise leave unset");
	} else {
		token = Storage::checkString("currently no flats present\nwill be left unassigned");
	}

	if (token.compare("YES") == 0) {
		// just to check if valid index is entered
		std::vector<unsigned int> existingFlats;
		for (i = 0; i< Storage::flats.size(); ++i) {
			std::cout<<"ID: "<<i<<'\t'<<Storage::flats.at(i)->getAddress()<<std::endl;
			existingFlats.push_back(int(i));
		}
		i = Storage::checkUInt("enter flat ID",&existingFlats);
		std::cout<<"removing prior owner "<<Storage::flats.at(i)->getOwnerPtr()->getName()<<std::endl;
		Storage::flats.at(i)->setOwnerPtr(std::make_shared<Vermieter>(*this));
	}

	// income is kept = 0 !!!
}

std::string Vermieter::csvLine() {
	return "2," + Person::csvLine() + ',' + std::to_string(income);
}

void Vermieter::readProperties(std::vector<std::string> *values, unsigned int shift) {
	this -> id = std::stoul(values->at(0)) + shift;
	this-> name = values->at(1);
	this-> age = std::stoul(values->at(2));
	this -> income = std::stod(values->at(3));
}

