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
#include <memory> // for unique_ptr
#include <iomanip>
#include <limits>
#include <string>

#include "../includes/Person.h"
#include "../includes/Vermieter.h"
#include "../includes/Mieter.h"
#include "../includes/MietObject.h"

class Storage {
	public:
		Storage();
		static void listPersons();
		static void listFlats();
		static void addPerson();
		static void addFlat();
		static int checkInt(const std::string&);
		static double checkDouble(const std::string&);
		//static void adoptVermieter(std::unique_ptr<Person>&);
		static void adoptVermieter(Vermieter*);

	private:
		static std::vector<std::unique_ptr<Person>> persons;
		static std::vector<std::unique_ptr<MietObject>> flats;
};

#endif /* SRC_INCLUDES_STORAGE_H_ */
