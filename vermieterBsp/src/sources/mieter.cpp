/*
 * mieter.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/Mieter.h"
#include "../includes/Storage.h"

#include <string>

Mieter::Mieter() : Person() {
	expenses = 0.0;
}

double Mieter::getBalance(){
	double rate = Storage::flats.at(getFlat())->getRate();
	expenses = monthsInFlat * rate;
	return expenses;
}
void Mieter::setBalance(double expenses) {
	this->expenses = expenses;
}
void Mieter::printToScreen(){
	std::cout<<"\nMieter\t";
	Person::printToScreen();
	std::cout<<"Buerge:\t"<<getBuerge()<<std::endl;
	std::cout<<"expenses:\t"<<getExpenses()<<std::endl;
}
const std::string& Mieter::getBuerge() const {
	return buerge;
}
void Mieter::setBuerge(const std::string& buerg) {
	this->buerge = buerg;
}
void Mieter::setFlat(int flatIndex) {
	this->flatIndex = flatIndex;
}
int Mieter::getFlat() const {
	return this->flatIndex;
}
void Mieter::setProperties() {
	Person::setProperties();
	std::cout<<"assign existing flat to Mieter"<<std::endl;
	setBuerge(Storage::checkString("enter Buerge"));
	setFlat(0); //TODO
}

std::string Mieter::csvLine(){
	return "1;" + Person::csvLine() + ';' + getBuerge() + ';' + std::to_string(getExpenses()) + ';' + std::to_string(getFlat());
}
void Mieter::readProperties(std::vector<std::string> *values) {
	setName(values->at(0));
	setAge(std::stoul(values->at(1)));
	setBuerge(values->at(2));
	setExpenses(std::stod(values->at(3)));
	setFlat(std::stoi(values->at(4)));
}

void Mieter::setMonthsInFlat(double months){
	this->monthsInFlat = months;
}

double Mieter::getMonthsInFlat(){
	return this->monthsInFlat;
}
