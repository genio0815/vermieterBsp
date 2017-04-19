/*
 * menu.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: alex
 */

#include "../includes/Menu.h"

std::vector<std::string> mainOpts = {"Persons Submenu", "Flats Submenu", "Quit"};
std::vector<std::string> flatOpts = {"List flats", "Add flat", "Return to main menu", "Quit"};
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
			std::cout<<"i will list persons"<<std::endl;
			Storage::listPersons();
			break;
		case 2:
			std::cout<<"i will add person"<<std::endl;
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
			// Do nothing - we won't change the menu
		}
	}
	return aNewMenu;
}

FlatsMenu::FlatsMenu() : BaseMenu(){
	this->optPt = &flatOpts;
}

std::unique_ptr<BaseMenu> FlatsMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) {
	std::unique_ptr<BaseMenu> aNewMenu = 0;
	switch (choice)
	{
		case 1:
			std::cout<<"i will list flats"<<std::endl;
			break;
		case 2:
			std::cout<<"i will add flat"<<std::endl;
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
			// Do nothing - we won't change the menu
		}
	}
	return aNewMenu;
}
