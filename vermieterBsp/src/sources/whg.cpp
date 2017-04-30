//
// Created by Bindeus, Alexander on 4/20/17.
//

#include "../includes/Whg.h"
#include "../includes/Storage.h"

Whg::Whg() {
}

void Whg::printToScreen() {
    MietObject::printToScreen();
    std::cout<<"object type:\tWHG"<<std::endl;
    std::cout<<"categroy:\t"<<category<<std::endl;
}

void Whg::setProperties() {
	MietObject::setProperties();
	if (owner == nullptr) return;
	this->category = Storage::checkString("enter Whg Kategorie");
}

std::string Whg::csvLine() {
	return "4," + MietObject::csvLine() + ',' + category;
}

void Whg::readProperties(std::vector<std::string> *values, unsigned int shift) {
	unsigned int index;
	this->address = values->at(0);
	this->size = std::stod(values->at(1));
	this->prize = std::stod(values->at(2));
	this->monthlyRate = std::stod(values->at(3));

	if (values->at(4) == "NONE") {
		this->owner = nullptr;
	} else {
		 index = (std::stoul(values->at(4)));
		this->owner = std::static_pointer_cast<Vermieter>(Storage::persons.at(index + shift));
	}

	if (values->at(5) == "NONE") {
		this->renter = nullptr;
	} else {
		index = (std::stoul(values->at(5)));
		this->renter = std::static_pointer_cast<Mieter>(Storage::persons.at(index + shift));
	}
	this-> category = values->at(6);
}
