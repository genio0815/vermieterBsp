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
		// virtual (get reused & expanded in derived):
		virtual void printToScreen();
		virtual ~Person() {}; // quick & dirty
		virtual void setProperties();
		virtual std::string csvLine();

		// pure virtual (have to be implemented in derived):
		virtual void readProperties(std::vector<std::string> *) = 0;
		virtual double getBalance() = 0;
		virtual void updateBalance(double) = 0;

		// just used for one child...ugly but avoid visitor pattern
		void removeFlat(unsigned int) {};
		void setMonthsInFlat(double) {};

	protected:
		std::string name;
		unsigned int age;
};

#endif
