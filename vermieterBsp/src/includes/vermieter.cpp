/*
 * vermieter.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../header/Vermieter.h"
#include <algorithm>

Vermieter::Vermieter(const std::string& name, unsigned int age) : Person(name,age) {
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
void Vermieter::printToScreen() {
	Person::printToScreen();
	std::cout<<"income:\t"<<getIncome()<<std::endl;
	std::cout<<"number of flats:\t"<<numberFlat()<<std::endl;
}
void Vermieter::addFlat(const MietObject newFlat) {
	this->ownedFlats.push_back(newFlat);
}
void Vermieter::removeFlatByIndex(int index) {
	this->ownedFlats.erase(ownedFlats.begin()+index);
}
int Vermieter::numberFlat() {
	return this->ownedFlats.size();
}
