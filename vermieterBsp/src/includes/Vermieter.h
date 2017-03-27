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

class Vermieter: protected Person {
	public:
		Vermieter(const std::string& name, unsigned int age);
		double getIncome() const;
		void setIncome(double income);
		void printToScreen();
		void addFlat(MietObject);
		void removeFlatByIndex(int index);
		int numberFlat();

		~Vermieter();

	private:
		double income;
		std::vector<MietObject> ownedFlats;
};

#endif
