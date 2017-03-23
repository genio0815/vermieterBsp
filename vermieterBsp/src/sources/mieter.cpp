/*
 * mieter.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/Mieter.h"

Mieter::Mieter(const std::string& name, unsigned int age) : Person(name,age) {
	expenses = 0.0;
}
double Mieter::getExpenses() const {
	return expenses;
}
void Mieter::setExpenses(double expenses) {
	this->expenses = expenses;
}
void Mieter::printToScreen() const {
	Person::printToScreen();
	std::cout<<"expenses:\t"<<getExpenses()<<std::endl;
}
const std::string& Mieter::getMovingInDate() const {
	return movingInDate;
}
void Mieter::setMovingInDate(const std::string& movingInDate) {
	this->movingInDate = movingInDate;
}

