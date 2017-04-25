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
#include<vector>
#include "../includes/Person.h"

// has to be public to pack it all into one vector of unique_ptr !!!
class Mieter: public Person {
	public:
		Mieter();

		double getBilance();
		void setBilance(double);
		void printToScreen();
		const std::string& getBuerge() const;
		void setBuerge(const std::string &);
		void setProperties();
		void setFlat(int);
		int getFlat() const;
		virtual std::string csvLine();
		virtual void readProperties(std::vector<std::string> *);
		void setMonthsInFlat(double);
		double getMonthsInFlat();

	private:
		int flatIndex;
		double monthsInFlat;
		double expenses;
		std::string buerge;
};

#endif
