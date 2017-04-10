/*
 * myMain.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: alex
 */

#include <limits>
#include <memory> // for unique_ptr

#include "includes/Haus.h"
#include "includes/MietObject.h"
#include "includes/Mieter.h"
#include "includes/Person.h"
#include "includes/Vermieter.h"
#include "includes/Menu.h"

using namespace std;

//void mainMenu(vector<Person> *persons, vector<MietObject> *accs) {


int main() {

	unique_ptr<BaseMenu> aCurrentMenu(new MainMenu);
	bool isQuitOptionSelected = false;
	while (!isQuitOptionSelected)
	{
		aCurrentMenu->printText();

		int choice = 0;
		cin >> choice;

		if (cin.fail()) {
			cin.clear(); // clears error flags
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove all if entered more than 1 letter
		}

		unique_ptr<BaseMenu> aNewMenuPointer(aCurrentMenu->getNextMenu(choice, isQuitOptionSelected));

		if (aNewMenuPointer) aCurrentMenu = move(aNewMenuPointer);
	}

	vector<Person> persons;
	vector<MietObject> accomodations;

	//mainMenu(&persons, &accomodations);

	Person test2("hugo",42);
	test2.printToScreen();

	MietObject schassHittn;
	Haus schassHittn2;

	Vermieter vermieter1("heinzi",45);
	vermieter1.printToScreen();
	vermieter1.addFlat(schassHittn);
	vermieter1.addFlat(schassHittn2);
	vermieter1.printToScreen();
	vermieter1.removeFlatByIndex(10);
	vermieter1.printToScreen();

	return 0;
}



