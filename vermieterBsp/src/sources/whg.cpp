//
// Created by Bindeus, Alexander on 4/20/17.
//

#include "../includes/Whg.h"
#include "../includes/Storage.h"

Whg::Whg() {

}
Whg::Whg(const std::string& address, double size, double prize) : MietObject(address, size, prize) {
    setCategory("A");
    //this->floors = 0;
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
