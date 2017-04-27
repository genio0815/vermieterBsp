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
        virtual void updateBalance(double);
		double getBalance();
		void setBalance(double);
		void printToScreen();
		void addFlat();
		size_t numberFlat();
		void setProperties();
		std::string csvLine();
		virtual void readProperties(std::vector<std::string> *);
		void removeFlat(unsigned int);

	private:
		double income;
		std::vector<unsigned int> ownedFlats; // stored via flats ID index
};

#endif
