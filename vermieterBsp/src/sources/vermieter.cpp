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

double Vermieter::getBalance() {
	return income;
}

void Vermieter::updateBalance(double income){
	this->income += income;
}
void Vermieter::setBalance(double income) {
	this->income = income;
}
void Vermieter::printToScreen(){
	std::cout<<"\nVermieter\t";
	Person::printToScreen();
	std::cout<<"income:\t"<<income<<std::endl;
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
		Storage::addFlat();
	} else if (token.compare("EX") == 0) {
		if (Storage::flats.size() > 0) {
			// just to check if valid index is entered
			std::vector<int> existingFlats;
			for (unsigned int i = 0; i< Storage::flats.size(); ++i) {
				existingFlats.push_back(int(i));
			}
			token = Storage::checkString("\nto list existing flats enter: YES");
			if (token.compare("YES") == 0) Storage::listFlats();
			int index = Storage::checkInt("enter flat ID",&existingFlats);
			Storage::flats.at(index)->setOwnerPtr(std::make_shared<Vermieter>(*this));
		}
	}
}

std::string Vermieter::csvLine() {
	return "2;" + Person::csvLine() + ';' + std::to_string(income) + ';' ;//+ std::to_string(numberFlat());
}

void Vermieter::readProperties(std::vector<std::string> *values) {
	this-> name = values->at(0);
	this-> age = std::stoul(values->at(1));
	setBalance(std::stod(values->at(2)));
}

