/*
 * mietobject.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/MietObject.h"

MietObject::MietObject(){
//	this->setPrize(0.0);
//	this->setSize(0.0);
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
const std::string& MietObject::getAdress() const {
	return adress;
}
void MietObject::setAdress(const std::string& adress) {
	this->adress = adress;
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
