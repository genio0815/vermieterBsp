/*
 * storage.h
 *
 *  Created on: Apr 12, 2017
 *      Author: alexander.bindeus
 */

#ifndef SRC_INCLUDES_STORAGE_H_
#define SRC_INCLUDES_STORAGE_H_

#include <iostream>
#include <vector>

#include "../includes/Person.h"
#include "../includes/MietObject.h"

class Storage {
	public:
		Storage();
		void listPersons();
		void listFlats();
		void addPerson(Person addMe);
		void addFlat(MietObject addMe);

	private:
		static std::vector<Person> persons;
		static std::vector<MietObject> flats;
};

#endif /* SRC_INCLUDES_STORAGE_H_ */
