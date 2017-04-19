/*
 * vermieter.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include <algorithm>
#include "../includes/Vermieter.h"

Vermieter::Vermieter(std::string& name, int age) : Person(name,age) {
	income = 0.0;
	ownedFlats.resize(0);
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
	setIncome(100.0);
	ownedFlats.resize(100);
}
