/*
 * Mieter.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef SRC_INCLUDES_MIETER_H_
#define SRC_INCLUDES_MIETER_H_

#include "../includes/Person.h"

class Mieter: protected Person {
	public:
		Mieter(const std::string& name, unsigned int age);

		double getExpenses() const;
		void setExpenses(double expenses);
		void printToScreen() const;
		const std::string& getMovingInDate() const;
		void setMovingInDate(const std::string& movingInDate) ;
	private:
		double expenses;
		std::string movingInDate;
};

#endif
