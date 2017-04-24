/*
 * Vermieter.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef SRC_INCLUDES_VERMIETER_H_
#define SRC_INCLUDES_VERMIETER_H_

#include <vector>

#include "../includes/Person.h"
#include "../includes/MietObject.h"


// has to be public to pack it all into one vector of unique_ptr !!!
class Vermieter: public Person {
	public:
		Vermieter();
		double getIncome() const;
		void setIncome(double);
		void printToScreen();
		void addFlat();
		void removeFlatByIndex(int);
		size_t numberFlat();
		void setProperties();
		std::string csvLine();
		virtual void readProperties(std::vector<std::string> *);

		~Vermieter();

	private:
		double income;
		std::vector<int> ownedFlats; // stored via flats ID index
};

#endif
