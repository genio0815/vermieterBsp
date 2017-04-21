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

MietObject::MietObject(const std::string& address, double size, double prize){
	setAddress(address);
	setPrize(prize);
	setSize(size);
}

void MietObject::printToScreen() {
	std::cout<<"Addresse:\t"<<getAddress()<<std::endl;
	std::cout<<"Groesse:\t"<<getSize()<<std::endl;
	std::cout<<"Preis:\t"<<getPrize()<<std::endl;
}

void MietObject::setProperties() {
	std::cout<<"will add MietObject porps"<<std::endl;
	std::cout<<"\nenter Address ";
	std::getline(std::cin,address);
	size = Storage::checkDouble("enter size");
	prize = Storage::checkDouble("enter prize");
	// owner
	// renter
}

double MietObject::getPrize() const {
	return prize;
}
void MietObject::setPrize(double prize) {
	this->prize = prize;
}
double MietObject::getSize() const {
	return size;
}
void MietObject::setSize(double size) {
	this->size = size;
}
const std::string& MietObject::getAddress() const {
	return address;
}
void MietObject::setAddress(const std::string& address) {
	this->address = address;
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
