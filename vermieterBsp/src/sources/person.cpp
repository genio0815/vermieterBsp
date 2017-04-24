/*
 * person.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */


#include "../includes/Person.h"
#include "../includes/Storage.h"

Person::Person(){
}

void Person::setProperties() {
	name = Storage::checkString("enter Name");
	age = Storage::checkUInt("enter Age");
}

void Person::printToScreen(){
	std::cout<<getName()<<"\tage:\t"<<getAge()<<std::endl;
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

std::string Person::csvLine(){
	return getName() + ';' + std::to_string(getAge());
}
void Person::readProperties(std::vector<std::string> *) {
}

