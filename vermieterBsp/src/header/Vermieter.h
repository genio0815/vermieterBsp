/*
 * Vermieter.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef SRC_HEADER_VERMIETER_H_
#define SRC_HEADER_VERMIETER_H_

#include <vector>
#include "../header/Person.h"
#include "../header/MietObject.h"

class Vermieter: protected Person {
	public:
		Vermieter(const std::string& name, unsigned int age);
		double getIncome() const;
		void setIncome(double income);
		void printToScreen();
		void addFlat(const MietObject);
		void removeFlatByIndex(int index);
		int numberFlat();

		~Vermieter();

	private:
		double income;
		std::vector<MietObject> ownedFlats;
};

#endif /* SRC_HEADER_VERMIETER_H_ */
