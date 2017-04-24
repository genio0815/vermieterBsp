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

double Mieter::getExpenses() const {
	return expenses;
}
void Mieter::setExpenses(double expenses) {
	this->expenses = expenses;
}
void Mieter::printToScreen(){
	std::cout<<"\nMieter\t";
	Person::printToScreen();
	std::cout<<"Einzugs Datum:\t"<<getMovingInDate()<<std::endl;
	std::cout<<"expenses:\t"<<getExpenses()<<std::endl;
}
const std::string& Mieter::getMovingInDate() const {
	return movingInDate;
}
void Mieter::setMovingInDate(const std::string& movingInDate) {
	this->movingInDate = movingInDate;
}
void Mieter::setFlat(int flatIndex) {
	this->flatIndex = flatIndex;
}
int Mieter::getFlat() const {
	return this->flatIndex;
}
void Mieter::setProperties() {
	Person::setProperties();
	movingInDate = Storage::checkString("enter Einzugs Datum");
	setFlat(0);
}

std::string Mieter::csvLine(){
	return "1;" + Person::csvLine() + ';' + getMovingInDate() + ';' + std::to_string(getExpenses()) + ';' + std::to_string(getFlat());
}
void Mieter::readProperties(std::vector<std::string> *values) {
	setName(values->at(0));
	setAge(std::stoul(values->at(1)));
	setMovingInDate(values->at(2));
	setExpenses(std::stod(values->at(3)));
	setFlat(std::stoi(values->at(4)));
}
