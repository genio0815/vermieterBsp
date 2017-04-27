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
	std::cout<<"income:\t"<<income<<"\tnumber of flats:\t"<<numberFlat()<<std::endl;
}
void Vermieter::addFlat() {
	//this->ownedFlats.emplace_back(newFlat);
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
			// just to check if valid index is entered
			std::vector<int> existingFlats;
			for (unsigned int i = 0; i< Storage::flats.size(); ++i) {
				existingFlats.push_back(int(i));
			}
			token = Storage::checkString("\nto list existing flats enter: YES");
			if (token.compare("YES")) Storage::listFlats();
			int index = Storage::checkInt("enter flat ID",&existingFlats);
			// inhibit assigning the same flat twice to same owner
			if (std::find(ownedFlats.begin(), ownedFlats.end(), index) != ownedFlats.end()) {
				std::cout<<"selected flat is already owned by Vermieter "<<name<<std::endl;
			} else {
				// deleting prior owner from flat (there can be just one) and assign new one
				Storage::deleteOwnerFromFlat((unsigned int)index);
				ownedFlats.push_back(index);
			}
		}
	}
}

void Vermieter::removeFlat(unsigned int flatId){
	std::vector<unsigned int>::iterator position = std::find(ownedFlats.begin(), ownedFlats.end(), flatId);
	if (position != ownedFlats.end())
		ownedFlats.erase(position);
}

std::string Vermieter::csvLine() {
	std::string flatindices = ";";
	for (auto &flat : ownedFlats) {
		flatindices += "/" + std::to_string(flat);
	}
	return "2;" + Person::csvLine() + ';' + std::to_string(income) + ';' + std::to_string(numberFlat()) + flatindices;
}

void Vermieter::readProperties(std::vector<std::string> *values) {
	this-> name = values->at(0);
	this-> age = std::stoul(values->at(1));
	setBalance(std::stod(values->at(2)));
	std::vector<unsigned int> flatindices = Storage::splitUInt(values->at(3),"/");
	for (auto &ind : flatindices) {
		ownedFlats.push_back(ind);
	}
}

