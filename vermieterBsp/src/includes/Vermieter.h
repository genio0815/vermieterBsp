/*
 * Vermieter.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef SRC_INCLUDES_VERMIETER_H_
#define SRC_INCLUDES_VERMIETER_H_

#include <vector>
#include <memory> // for unique_ptr

#include "../includes/Person.h"
#include "../includes/MietObject.h"


// has to be public to pack it all into one vector of unique_ptr !!!
class Vermieter: public Person {
	public:
		Vermieter(std::string& name, int age);
		double getIncome() const;
		void setIncome(double income);
		void printToScreen();
		void addFlat();
		void removeFlatByIndex(int index);
		size_t numberFlat();
		void setProperties();

		~Vermieter();

	private:
		double income;
		std::vector<std::unique_ptr<MietObject>> ownedFlats;
};

#endif
