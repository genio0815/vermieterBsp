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

	unsigned int i;
	std::string token;

	// change 2804: new Mieter HAS to be assigned ONLY to existing flat
	std::cout<<"new Renter have to be assigned to existing flats"<<std::endl;
	if (Storage::flats.size() > 0) {
		std::vector<unsigned int> existingFlats;
		std::cout<<"available flats:\n"<<std::endl;
		for (i = 0; i< Storage::flats.size(); ++i) {
			if(Storage::flats.at(i)-> getRenterPtr() == nullptr) {
				existingFlats.push_back(i);
				std::cout<<"ID: "<<i<<'\t'<<Storage::flats.at(i)-> getAddress()<<std::endl;
			}
		}
		if (existingFlats.size() == 0) {
			std::cout<<"sorry, currently no flats available..."<<std::endl;
			return;
		}

		std::cout<<std::endl;
		i = Storage::checkUInt("enter flat ID",&existingFlats);
		Storage::flats.at(i)->setRenterPtr(std::static_pointer_cast<Mieter>(Storage::persons.back()));

		std::cout<<"assigned flat, continue with renter properties\n"<<std::endl;

		Person::setProperties();
		buerge = Storage::checkString("enter Buerge");

	} else {
		std::cout<<"no flats present..."<<std::endl;
	}
}

std::string Mieter::csvLine(){
	return "1," + Person::csvLine() + ',' + buerge + ',' + std::to_string(expenses) + ',' + std::to_string(monthsInFlat);
}
void Mieter::readProperties(std::vector<std::string> *values, unsigned int shift) {
	this -> id = std::stoul(values->at(0)) + shift;
	this-> name = values->at(1);
	this-> age = std::stoul(values->at(2));
	this-> buerge = values->at(3);
	this-> expenses = std::stod(values->at(4));
	this-> monthsInFlat = std::stod(values->at(5));
}

void Mieter::setMonthsInFlat(double months){
	this->monthsInFlat += months;
}
