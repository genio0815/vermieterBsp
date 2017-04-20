/*
 * Person.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef INCLUDES_PERSON_H_
#define INCLUDES_PERSON_H_

#include <iostream>
#include <string>

class Person {
	public:
		Person(std::string& name, int age);
		virtual void printToScreen();
		virtual ~Person() {}; // quick & dirty
		virtual void setProperties();
		int getAge() const;
		void setAge(int age);
		const std::string& getName() const;
		void setName(const std::string& name);
	private:
		std::string name;
		int age;
};

#endif
