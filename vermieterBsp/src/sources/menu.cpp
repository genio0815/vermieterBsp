/*
 * menu.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: alex
 */

#include "../includes/Menu.h"

std::vector<std::string> mainOpts = {"Persons Submenu", "Flats Submenu", "Quit"};
std::vector<std::string> flatOpts = {"list flats", "add flat", "return to main menu", "quit"};
std::vector<std::string> personOpts = {"list persons", "add person", "return to main menu", "quit"};

BaseMenu::BaseMenu() {
}

void BaseMenu::printText() {
	std::cout<< "Please make your selection\n"<<std::endl;
	short choice = 0;
	for (auto &e : *optPt) {
		std::cout<<++choice<<'\t'<<e<<std::endl;
	}
}

MainMenu::MainMenu() : BaseMenu() {
	this->optPt = &mainOpts;
}

BaseMenu * MainMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) {
	BaseMenu *aNewMenu = 0;
	switch (choice) {
		case 1:
			aNewMenu = new PersonsMenu;
			break;
		case 2:
			aNewMenu = new FlatsMenu;
			break;
		case 3:
			iIsQuitOptionSelected = true;
			break;
		default: {
			std::cout<<"unrecognized input"<<std::endl;
			}
	}
	return aNewMenu;
}

PersonsMenu::PersonsMenu() : BaseMenu() {
	this->optPt = &personOpts;
}

BaseMenu * PersonsMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) {
	BaseMenu *aNewMenu = 0;
	switch (choice) {
		case 0:
			std::cout<<"invalid choice"<<std::endl;
			break;
		case 1:
			std::cout<<"i will list persons"<<std::endl;
			break;
		case 2:
			std::cout<<"i will add person"<<std::endl;
			break;
		case 3:
			std::cout<<"return to main menu"<<std::endl;
			aNewMenu = new MainMenu;
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

BaseMenu * FlatsMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) {
	BaseMenu *aNewMenu = 0;
	switch (choice)
	{
		case 0:
			std::cout<<"invalid choice"<<std::endl;
			break;
		case 1:
			std::cout<<"i will list flats"<<std::endl;
			break;
		case 2:
			std::cout<<"i will add flat"<<std::endl;
			break;
		case 3:
			std::cout<<"return to main menu"<<std::endl;
			aNewMenu = new MainMenu;
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
