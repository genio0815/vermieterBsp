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
	std::cout<<name<<"\tage:\t"<<age<<std::endl;
}

std::string Person::csvLine(){
	return name + ';' + std::to_string(age);
}
void Person::readProperties(std::vector<std::string> *) {
}

