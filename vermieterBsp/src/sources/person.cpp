/*
 * person.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */


#include "../includes/Person.h"

Person::Person(std::string& name, int age){
	setName(name);
	setAge(age);
}

void Person::setProperties() {}

void Person::printToScreen(){
	std::cout<<getName()<<"\tage:\t"<<getAge()<<std::endl;
}

int Person::getAge() const {
	return age;
}

void Person::setAge(int age) {
	this->age = age;
}

const std::string& Person::getName() const {
	return name;
}

void Person::setName(const std::string& name) {
	this->name = name;
}



