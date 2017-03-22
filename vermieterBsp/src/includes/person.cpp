/*
 * person.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */


#include "../header/Person.h"

Person::Person(const std::string& name, unsigned int age){
	setName(name);
	setAge(age);
}

void Person::printToScreen() const {
	std::cout<<"name:\t"<<getName()<<std::endl;
	std::cout<<"age:\t"<<getAge()<<std::endl;
}

unsigned int Person::getAge() const {
	return age;
}

void Person::setAge(unsigned int age) {
	this->age = age;
}

const std::string& Person::getName() const {
	return name;
}

void Person::setName(const std::string& name) {
	this->name = name;
}



