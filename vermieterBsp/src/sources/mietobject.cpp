/*
 * mietobject.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/MietObject.h"
#include "../includes/Storage.h"

MietObject::MietObject() {
	setPrize(0.0);
	setSize(0.0);
}

void MietObject::printToScreen() {
	std::cout<<"Addresse:\t"<<getAddress()<<std::endl;
	std::cout<<"Groesse:\t"<<getSize()<<std::endl;
	std::cout<<"Preis:\t"<<getPrize()<<std::endl;
}

void MietObject::setProperties() {
	address = Storage::checkString("enter Address");
	size = Storage::checkDouble("enter size");
	prize = Storage::checkDouble("enter prize");
	// owner
	// renter
}

double MietObject::getPrize(){
	return prize;
}
void MietObject::setPrize(double prize) {
	this->prize = prize;
}
double MietObject::getSize(){
	return size;
}
void MietObject::setSize(double size) {
	this->size = size;
}
const std::string& MietObject::getAddress(){
	return address;
}
void MietObject::setAddress(const std::string& address) {
	this->address = address;
}

std::string MietObject::csvLine() {
	return getAddress() + ';' + std::to_string(getSize()) + ';' + std::to_string(getPrize());
}

//Vermieter MietObject::getOwner() {
//	return this->owner;
//}
//
//Mieter MietObject::getRenter() {
//	return this->renter;
//}
//
//void MietObject::setOwner(Vermieter own) {
//	this->owner = own;
//}
//
//void MietObject::setRenter(Mieter rent) {
//	this->renter = rent;
//}
