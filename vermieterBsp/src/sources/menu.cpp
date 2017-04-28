/*
 * menu.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: alex
 */

#include "../includes/Menu.h"
#include <string>


std::vector<std::string> mainOpts = {"Persons Submenu", "Flats Submenu", "Proceed in time","Read input file", "Write to file" ,"Quit"};
std::vector<std::string> flatOpts = {"List flats", "Add flat", "Alter Flat Owner", "Alter Flat Renter",
									 "Return to main menu", "Quit"};
std::vector<std::string> personOpts = {"List persons", "Add person", "Return to main menu", "Quit"};

BaseMenu::BaseMenu() {
	optPt = 0;
}

void BaseMenu::printText() {
	std::cout<< "\nPlease make your selection\n"<<std::endl;
	short choice = 0;
	for (auto &e : *optPt) {
		std::cout<<++choice<<'\t'<<e<<std::endl;
	}
}

MainMenu::MainMenu() : BaseMenu() {
	this->optPt = &mainOpts;
}

std::unique_ptr<BaseMenu> MainMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) {
	std::unique_ptr<BaseMenu> aNewMenu;
	switch (choice) {
		case 1:
			aNewMenu = std::unique_ptr<BaseMenu>(new PersonsMenu);
			break;
		case 2:
			aNewMenu = std::unique_ptr<BaseMenu>(new FlatsMenu);
			break;
		case 3:
			Storage::proceedInTime();
			break;
		case 4: {
			std::string infile;
			std::cout<<"\nenter file name: ";
			std::cin >> infile;
			Storage::readCSV(infile);
			break;
		}
		case 5:
			Storage::writeCSV("myCsv.csv");
			break;
		case 6:
			iIsQuitOptionSelected = true;
			break;
		default: {
			std::cerr<<"unrecognized input "<<choice<<std::endl;
		}
	}
	return aNewMenu;
}

PersonsMenu::PersonsMenu() : BaseMenu() {
	this->optPt = &personOpts; // def. value
}

std::unique_ptr<BaseMenu> PersonsMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) {
	std::unique_ptr<BaseMenu> aNewMenu;
	switch (choice) {
		case 0:
			std::cerr<<"invalid choice"<<std::endl;
			break;
		case 1:
			Storage::listPersons();
			break;
		case 2:
			Storage::addPerson();
			break;
		case 3:
			std::cout<<"return to main menu"<<std::endl;
			aNewMenu = std::unique_ptr<BaseMenu>(new MainMenu);
			break;
		case 4:
			iIsQuitOptionSelected = true;
			break;
		default:
		{
			// nothing
		}
	}
	return aNewMenu;
}

FlatsMenu::FlatsMenu() : BaseMenu(){
	this->optPt = &flatOpts;
}

std::unique_ptr<BaseMenu> FlatsMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) {
	std::unique_ptr<BaseMenu> aNewMenu;
	switch (choice)
	{
		case 1:
			Storage::listFlats();
			break;
		case 2:
			Storage::addFlat();
			break;
		case 3:
			Storage::changeOwner();
			break;
		case 4:
			Storage::changeRenter();
			break;
		case 5:
			std::cout<<"return to main menu"<<std::endl;
			aNewMenu = std::unique_ptr<BaseMenu>(new MainMenu);
			break;
		case 6:
			iIsQuitOptionSelected = true;
			break;
		default:
		{
			// nothing
		}
	}
	return aNewMenu;
}
