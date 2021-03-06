/*
 * myMain.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: alex
 */

#include <limits>
#include <memory>
#include "includes/Person.h"
#include "includes/Vermieter.h"
#include "includes/Mieter.h"
#include "includes/Haus.h"

// fucking include guard mix up !!!
#include "includes/MietObject.h"
#include "includes/Menu.h"

using namespace std;

void showMainMenu() {
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
	cout<<"\nBye Bye..."<<endl;
}

int main() {

	showMainMenu();
	return 0;
}



