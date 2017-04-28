/*
 * Mieter.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef SRC_INCLUDES_MIETER_H_
#define SRC_INCLUDES_MIETER_H_

#include <iomanip>
#include <limits>
#include <vector>
#include <memory>

#include "../includes/Person.h"

class MietObject;

// has to be public to pack it all into one vector!!!
class Mieter: public Person {
	public:
		Mieter();
		virtual void updateBalance(double);
		void printToScreen();
		void setProperties();
		virtual std::string csvLine();
		virtual void readProperties(std::vector<std::string> *);
		void setMonthsInFlat(double);

	private:
		double monthsInFlat;
		double expenses;
		std::string buerge;
};

#endif
