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
#include <vector>

class Person {
	public:
		Person();

		std::string getName();
		void setId(unsigned int);
		unsigned int getId();
		// virtual (get reused & expanded in derived):
		virtual void printToScreen();
		virtual ~Person() {}; // quick & dirty
		virtual void setProperties();
		virtual std::string csvLine();

		// pure virtual (have to be implemented in derived):
		virtual void readProperties(std::vector<std::string> *) = 0;
		virtual void updateBalance(double) = 0;

	protected:
		std::string name;
		unsigned int age;
		unsigned int id;
};

#endif
