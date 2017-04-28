//
// Created by Bindeus, Alexander on 4/20/17.
//

#include "../includes/Whg.h"
#include "../includes/Storage.h"

Whg::Whg() {

}

void Whg::printToScreen() {
    MietObject::printToScreen();
    std::cout<<"categroy:\t"<<category<<std::endl;
}

void Whg::setProperties() {
	MietObject::setProperties();
	this->category = Storage::checkString("enter Whg Kategorie");
}

std::string Whg::csvLine() {
	return "4;" + MietObject::csvLine() + ';' + category;
}

void Whg::readProperties(std::vector<std::string> *values) {
	this-> address = values->at(0);
	this-> isAvailable = (values->at(1) == "1" ?  true : false);
	this-> size = stod(values->at(2));
	this-> prize = stod(values->at(3));
	//this-> ownerId = std::stoul(values->at(4));
	//this-> renterId = std::stoul(values->at(5));
	this-> category = values->at(6);
}
