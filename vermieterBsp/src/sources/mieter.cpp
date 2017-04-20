/*
 * mieter.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/Mieter.h"

Mieter::Mieter(std::string& name, int age) : Person(name,age) {
	this->expenses = 0.0;
	this->flatIndex = 0;
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
int Mieter::getFlat() {
	return this->flatIndex;
}
void Mieter::setProperties() {
	std::string datum;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout<<"\nenter Einzugs Datum ";
	std::getline(std::cin, datum);
	setMovingInDate(datum);
	setExpenses(10000.0);
	setFlat(0);
}
