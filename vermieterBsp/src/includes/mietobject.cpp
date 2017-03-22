/*
 * mietobject.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../header/MietObject.h"

MietObject::MietObject(){
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



