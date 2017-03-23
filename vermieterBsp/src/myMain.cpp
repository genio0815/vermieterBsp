/*
 * myMain.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: alex
 */

#include "includes/Haus.h"
#include "includes/Mieter.h"
#include "includes/MietObject.h"
#include "includes/Person.h"
#include "includes/Vermieter.h"
#include "includes/Menu.h"

#include <limits>

using namespace std;

//void mainMenu(vector<Person> *persons, vector<MietObject> *accs) {


int main() {

	BaseMenu* aCurrentMenu = new FirstMenu; // We have a pointer to our menu. We're using a pointer so we can change the menu seamlessly.
	bool isQuitOptionSelected = false;
	while (!isQuitOptionSelected) // We're saying that, as long as the quit option wasn't selected, we keep running
	{
		aCurrentMenu->printText(); // This will call the method of whichever MenuObject we're using, and print the text we want to display

		int choice = 0; // Always initialise variables, unless you're 100% sure you don't want to.
		cin >> choice;

		if (cin.fail()) {
			cin.clear(); // clears error flags
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove all if entered more than 1 letter
		}

		BaseMenu* aNewMenuPointer = aCurrentMenu->getNextMenu(choice, isQuitOptionSelected); // This will return a new object, of the type of the new menu we want. Also checks if quit was selected

		if (aNewMenuPointer) // This is why we set the pointer to 0 when we were creating the new menu - if it's 0, we didn't create a new menu, so we will stick with the old one
		{
			delete aCurrentMenu; // We're doing this to clean up the old menu, and not leak memory.
			aCurrentMenu = aNewMenuPointer; // We're updating the 'current menu' with the new menu we just created
		}
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



