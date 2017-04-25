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
		virtual void printToScreen();
		virtual ~Person() {}; // quick & dirty
		virtual void setProperties();
		virtual std::string csvLine();
		virtual void readProperties(std::vector<std::string> *);
		// add following for childs and override them...otherwise i'd implement visitor pattern...
		void removeFlat(unsigned int) {};
		double getExpenses() {return 0.0;};

	protected:
		unsigned int getAge() const;
		void setAge(unsigned int age);
		const std::string& getName() const;
		void setName(const std::string &);

	private:
		std::string name;
		unsigned int age;
};

#endif
