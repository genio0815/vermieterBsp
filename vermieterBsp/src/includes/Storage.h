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
#include "../includes/Haus.h"
#include "../includes/Whg.h"

class Storage {
	public:
		Storage();
		static void listPersons();
		static void listFlats();
		static void addPerson();
		static void addFlat();
		static int checkInt(const std::string&, std::vector<int>*);
		static double checkDouble(const std::string&);
		static std::string checkString(const std::string&);
		static bool checkBool(const std::string&);
		static unsigned int checkUInt(const std::string&);
		static void adoptVermieter(Vermieter*);
		static std::vector<std::shared_ptr<Person> > persons;
		static std::vector<std::shared_ptr<MietObject> > flats;
		static void readCSV(const std::string&);
		static void writeCSV(const std::string&);
		static std::vector<std::string> split(const std::string& str, const std::string& delim);
		static std::vector<unsigned int> splitUInt(const std::string& str, const std::string& delim);
		static void proceedInTime();
};

#endif /* SRC_INCLUDES_STORAGE_H_ */
