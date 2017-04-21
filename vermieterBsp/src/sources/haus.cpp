/*
 * haus.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/Haus.h"
#include "../includes/Storage.h"

Haus::Haus() : MietObject() {
	setFloors(0);
	setHasCellar(false);
}

Haus::Haus(const std::string& address, double size, double prize) : MietObject(address, size, prize) {
	setFloors(0);
	setHasCellar(false);
}

const std::string& Haus::getConstuctionDate() const {
	return constuctionDate;
}

void Haus::setConstuctionDate(const std::string& constuctionDate) {
	this->constuctionDate = constuctionDate;
}

void Haus::printToScreen() {
	MietObject::printToScreen();
	std::cout<<"number floors:\t"<<getFloors()<<"\thas cellar\t"<<isHasCellar()<<std::endl;
	std::cout<<"construction date:\t"<<getConstuctionDate()<<std::endl;
}

unsigned int Haus::getFloors() const {
	return floors;
}

void Haus::setFloors(unsigned int floors) {
	this->floors = floors;
}

bool Haus::isHasCellar() const {
	return hasCellar;
}

void Haus::setHasCellar(bool hasCellar) {
	this->hasCellar = hasCellar;
}

void Haus::setProperties() {
	MietObject::setProperties();
	setConstuctionDate(Storage::checkString("enter Baujahr"));
	setFloors(Storage::checkUInt("Anzahl Stockwerke"));
	setHasCellar(Storage::checkBool("hat Keller"));
}
