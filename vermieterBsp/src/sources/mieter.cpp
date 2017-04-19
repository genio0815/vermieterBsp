/*
 * mieter.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/Mieter.h"

Mieter::Mieter(std::string& name, int age) : Person(name,age) {
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
	std::cout<<"expenses:\t"<<getExpenses()<<std::endl;
}
const std::string& Mieter::getMovingInDate() const {
	return movingInDate;
}
void Mieter::setMovingInDate(const std::string& movingInDate) {
	this->movingInDate = movingInDate;
}

void Mieter::setProperties() {
	setMovingInDate("jetzt");
	setExpenses(10000.0);
}
