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
#include "../includes/Person.h"

// has to be public to pack it all into one vector of unique_ptr !!!
class Mieter: public Person {
	public:
		Mieter(std::string& name, int age);

		double getExpenses() const;
		void setExpenses(double expenses);
		void printToScreen();
		const std::string& getMovingInDate() const;
		void setMovingInDate(const std::string& movingInDate);
		void setProperties();
		void setFlat(int flatIndex);
		int getFlat();

	private:
		int flatIndex;
		double expenses;
		std::string movingInDate;
};

#endif
