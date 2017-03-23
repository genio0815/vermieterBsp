/*
 * haus.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/Haus.h"


Haus::Haus() : MietObject() {
}

const std::string& Haus::getConstuctionDate() const {
	return constuctionDate;
}

void Haus::setConstuctionDate(const std::string& constuctionDate) {
	this->constuctionDate = constuctionDate;
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


