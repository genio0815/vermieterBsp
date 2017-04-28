/*
 * person.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */


#include "../includes/Person.h"
#include "../includes/Storage.h"

Person::Person(){
	age = 0;
	id = 0;
}

void Person::setProperties() {
	name = Storage::checkString("enter Name");
	age = Storage::checkUInt("enter Age", nullptr);
}

void Person::printToScreen(){
	std::cout<<name<<"\tage:\t"<<age<<std::endl;
}

std::string Person::csvLine(){
	return std::to_string(id) + ',' + name + ',' + std::to_string(age);
}

std::string Person::getName() {
	return name;
}

void Person::setId(unsigned int id) {
	this->id = id;
}

unsigned int Person::getId() {
	return id;
}
