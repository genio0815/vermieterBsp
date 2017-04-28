/*
 * mieter.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/Mieter.h"
#include "../includes/Storage.h"

#include <string>

Mieter::Mieter() : Person() {
	expenses = 0.0;
	monthsInFlat = 0.0;
}

void Mieter::updateBalance(double exp){
	expenses += exp;
}
void Mieter::printToScreen(){
	std::cout<<"\nMieter\t";
	Person::printToScreen();
	std::cout<<"Buerge:\t"<<buerge<<std::endl;
	std::cout<<"expenses:\t"<<expenses<<std::endl;
}

void Mieter::setProperties() {
	Person::setProperties();
	buerge = Storage::checkString("enter Buerge");
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
			Storage::flats.at(index)->setRenterPtr(std::make_shared<Mieter>(*this));
		}
	}
}

std::string Mieter::csvLine(){
	return "1;" + Person::csvLine() + ';' + buerge + ';' + std::to_string(expenses);
}
void Mieter::readProperties(std::vector<std::string> *values) {
	this-> name = values->at(0);
	this-> age = std::stoul(values->at(1));
	this-> buerge = values->at(2);
	this-> expenses = std::stod(values->at(3));
	//setFlat(std::stoi(values->at(4)));
}

void Mieter::setMonthsInFlat(double months){
	this->monthsInFlat += months;
}
