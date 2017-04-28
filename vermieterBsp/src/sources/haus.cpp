/*
 * haus.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/Haus.h"
#include "../includes/Storage.h"

Haus::Haus() : MietObject() {
	floors = 0;
	hasCellar = false;
}

void Haus::printToScreen() {
	MietObject::printToScreen();
	std::cout<<"number floors:\t"<<floors<<"\thas cellar\t"<<hasCellar<<std::endl;
	std::cout<<"construction date:\t"<<constructionDate<<std::endl;
}

void Haus::setProperties() {
	MietObject::setProperties();
	if (owner == nullptr) return;
	this->constructionDate = Storage::checkString("enter Baujahr");
	this->floors = Storage::checkUInt("Anzahl Stockwerke", nullptr);
	this->hasCellar = Storage::checkBool("hat Keller (0): No (1): Yes");
}

std::string Haus::csvLine() {
	return "3," + MietObject::csvLine() + ',' + constructionDate + ',' + std::to_string(floors) + ',' + std::to_string(hasCellar);
}

void Haus::readProperties(std::vector<std::string> *values) {
	this->address = values->at(0);
	this->size = std::stod(values->at(1));
	this->prize = std::stod(values->at(2));
	this->monthlyRate = std::stod(values->at(3));

	if (values->at(4) == "NONE") {
		this->owner = nullptr;
	} else {
		unsigned int i = (std::stoul(values->at(4)));
		this->owner = std::static_pointer_cast<Vermieter>(Storage::persons.at(i));
	}

	if (values->at(5) == "NONE") {
		this->renter = nullptr;
	} else {
		unsigned int i = (std::stoul(values->at(5)));
		this->renter = std::static_pointer_cast<Mieter>(Storage::persons.at(i));
	}

	this->constructionDate = values->at(6);
	this->floors = std::stoul(values->at(7));
	this->hasCellar = (values->at(8) == "1" ?  true : false);
}

