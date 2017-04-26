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
	isAvailable = true;
}

void MietObject::printToScreen() {
	std::cout<<"is Available:\t"<<(isAvailable ? "Yes" : "NO")<<std::endl;
	std::cout<<"Addresse:\t"<<address<<std::endl;
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

void MietObject::setRate(double rate) {
	this->monthlyRate = rate;
}

double MietObject::getRate() {
	return monthlyRate;
}

std::string MietObject::csvLine() {
	return address +';' + std::to_string(isAvailable)+ ';'  + std::to_string(getSize()) + ';' + std::to_string(getPrize()) +
			';' + std::to_string(getOwner()) + ';' + std::to_string(getRenter());
}

unsigned int MietObject::getOwner() {
	return this->ownerId;
}

unsigned int MietObject::getRenter() {
	return this->renterId;
}

void MietObject::setOwner(unsigned int ownId) {
	this->ownerId = ownId;
}

void MietObject::setRenter(unsigned int rentId) {
	this->renterId = rentId;
}

void MietObject::setProfit(double) {
	;
}

double MietObject::getProfit(){
	;
}
