//
// Created by Bindeus, Alexander on 4/20/17.
//

#include "../includes/Whg.h"
#include "../includes/Storage.h"

Whg::Whg() {

}

void Whg::printToScreen() {
    MietObject::printToScreen();
    std::cout<<"categroy:\t"<<getCategory()<<std::endl;
}

const std::string& Whg::getCategory() const {
    return this->category;
}

void Whg::setCategory(const std::string &cat) {
    this->category = cat;
}

void Whg::setProperties() {
	MietObject::setProperties();
	setCategory(Storage::checkString("enter Whg Kategorie"));
}

std::string Whg::csvLine() {
	return "4;" + MietObject::csvLine() + ';' + getCategory();
}

void Whg::readProperties(std::vector<std::string> *values) {
	setAddress(values->at(0));
	setAv(values->at(1) == "1" ?  true : false);
	setSize(std::stod(values->at(2)));
	setPrize(std::stod(values->at(3)));
	setOwner(std::stoul(values->at(4)));
	setRenter(std::stoul(values->at(5)));
	setCategory(values->at(6));
}
