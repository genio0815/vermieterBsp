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

Vermieter::~Vermieter() {
	std::cout<<"killing vermieter "<<Person::getName()<<std::endl;
}

double Vermieter::getIncome() const {
	return income;
}
void Vermieter::setIncome(double income) {
	this->income = income;
}
void Vermieter::printToScreen(){
	std::cout<<"\nVermieter\t";
	Person::printToScreen();
	std::cout<<"income:\t"<<getIncome()<<"\tnumber of flats:\t"<<numberFlat()<<std::endl;
}
void Vermieter::addFlat() {
	//this->ownedFlats.emplace_back(newFlat);
}
void Vermieter::removeFlatByIndex(int index) {
	this->ownedFlats.erase(ownedFlats.begin()+index);
}
size_t Vermieter::numberFlat() {
	return ownedFlats.size();
}

void Vermieter::setProperties() {
	Person::setProperties();
	std::string token;

	if (Storage::flats.size() > 0) {
		token = Storage::checkString("to add a new flat enter: NEW\nto asign existing flat via its ID enter EX\notherwise continue");
	} else {
		token = Storage::checkString("to add a new flat enter: NEW\n(currently no flats present)\notherwise continue");
	}

	if (token.compare("NEW") == 0) {
		int ok = Storage::addFlat();
		if (ok != -1) ownedFlats.push_back(ok);
	} else if (token.compare("EX") == 0) {
		if (Storage::flats.size() > 0) {
			std::vector<int> existingFlats;
			for (size_t i = 0; i< Storage::flats.size(); ++i) {
				existingFlats.push_back(i);
			}
			token = Storage::checkString("\nto list existing flats enter: YES");
			if (token.compare("YES")) Storage::listFlats();
			ownedFlats.push_back(Storage::checkInt("enter flat ID",&existingFlats));
		}
	}
}

std::string Vermieter::csvLine() {
	return "2;" + Person::csvLine() + ';' + std::to_string(getIncome()) + ';' + std::to_string(numberFlat());
}

void Vermieter::readProperties(std::vector<std::string> *values) {
	setName(values->at(0));
	setAge(std::stoul(values->at(1)));
	setIncome(std::stod(values->at(2)));
}

