/*
 * Vermieter.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef SRC_INCLUDES_VERMIETER_H_
#define SRC_INCLUDES_VERMIETER_H_

#include <vector>
#include <memory>

#include "../includes/Person.h"

class MietObject;

class Vermieter: public Person {
	public:
		Vermieter();
        virtual void updateBalance(double);
		void printToScreen();
		void setProperties();
		std::string csvLine();
		virtual void readProperties(std::vector<std::string> *);

		virtual bool getType() {return true;};

	private:
		double income;
};

#endif
