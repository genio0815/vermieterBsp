/*
 * mietobject.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/MietObject.h"
#include "../includes/Storage.h"

MietObject::MietObject() {
	prize = 0.0;
	size = 0.0;
	isAvailable = true;
}

void MietObject::printToScreen() {
	std::cout<<"is Available:\t"<<(isAvailable ? "Yes" : "NO")<<std::endl;
	std::cout<<"Addresse:\t"<<address<<std::endl;
	std::cout<<"Groesse:\t"<<size<<std::endl;
	std::cout<<"Preis:\t"<<prize<<std::endl;
}

void MietObject::setProperties() {
	address = Storage::checkString("enter Address");
	size = Storage::checkDouble("enter size");
	prize = Storage::checkDouble("enter prize");
	//TODO
	ownerId = Storage::checkUInt("enter Vermieter Id");
	renterId = Storage::checkUInt("enter Mieter Id");
}

std::string MietObject::csvLine() {
	return address +';' + std::to_string(isAvailable)+ ';'  + std::to_string(size) + ';' + std::to_string(prize) +
			';' + std::to_string(ownerId) + ';' + std::to_string(renterId);
}

unsigned int MietObject::getOwner() {
	return this->ownerId;
}

unsigned int MietObject::getRenter() {
	return this->renterId;
}

void MietObject::setOwner(unsigned int ownId) {
	this->ownerId = ownId;
}
//
//void MietObject::setRenter(unsigned int rentId) {
//	this->renterId = rentId;
//}

double MietObject::updateProfit(double time){
    if (!isAvailable) {
        profit += monthlyRate * time;
    }
	return profit;
}
