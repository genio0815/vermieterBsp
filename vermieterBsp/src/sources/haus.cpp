/*
 * haus.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/Haus.h"
#include "../includes/Storage.h"
#include <string>

Haus::Haus() : MietObject() {
	setFloors(0);
	setHasCellar(false);
}

const std::string& Haus::getConstructionDate(){
	return constuctionDate;
}

void Haus::setConstuctionDate(const std::string& constuctionDate) {
	this->constuctionDate = constuctionDate;
}

void Haus::printToScreen() {
	MietObject::printToScreen();
	std::cout<<"number floors:\t"<<getFloors()<<"\thas cellar\t"<<isHasCellar()<<std::endl;
	std::cout<<"construction date:\t"<<getConstructionDate()<<std::endl;
}

unsigned int Haus::getFloors(){
	return floors;
}

void Haus::setFloors(unsigned int floors) {
	this->floors = floors;
}

bool Haus::isHasCellar(){
	return hasCellar;
}

void Haus::setHasCellar(bool hasCellar) {
	this->hasCellar = hasCellar;
}

void Haus::setProperties() {
	MietObject::setProperties();
	setConstuctionDate(Storage::checkString("enter Baujahr"));
	setFloors(Storage::checkUInt("Anzahl Stockwerke"));
	setHasCellar(Storage::checkBool("hat Keller (0): No (1): Yes"));
}

std::string Haus::csvLine() {
	return "3;" + MietObject::csvLine() + ';' + getConstructionDate() + ';' + std::to_string(getFloors()) + ';' + std::to_string(isHasCellar());
}

void Haus::readProperties(std::vector<std::string> *values) {
	setAddress(values->at(0));
	setAv(values->at(1) == "1" ?  true : false);
	setSize(std::stod(values->at(2)));
	setPrize(std::stod(values->at(3)));
	setOwner(std::stoul(values->at(4)));
	setRenter(std::stoul(values->at(5)));
	setConstuctionDate(values->at(6));
	setFloors(std::stoul(values->at(7)));
	setHasCellar(values->at(8) == "1" ?  true : false);
}

