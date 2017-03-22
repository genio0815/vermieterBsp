/*
 * Person.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef HEADER_PERSON_H_
#define HEADER_PERSON_H_

#include <iostream>
#include <string>

class Person {
	public:
		Person(const std::string& name, unsigned int age);
		void printToScreen() const;
		unsigned int getAge() const;
		void setAge(unsigned int age);
		const std::string& getName() const;
		void setName(const std::string& name);
	private:
		std::string name;
		unsigned int age;
};

#endif /* HEADER_PERSON_H_ */
