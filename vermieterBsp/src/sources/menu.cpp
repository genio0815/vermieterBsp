/*
 * menu.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: alex
 */

#include "../includes/Menu.h"

BaseMenu::BaseMenu() {
	this->m_MenuText = "This shouldn't ever be shown!";
}

void BaseMenu::printText(std::vector<std::string> choices) {
	for (auto e : choices) {
		std::cout<<e<<std::endl;
	}
}

FirstMenu::FirstMenu() : BaseMenu() {
	m_MenuText = "Main Menu\n"
				 "Please make your selection\n"
				 "1 - List Persons\n"
				 "2 - List Accommodations\n"
				 "3 - Quit\n"
				 "Selection: ";
}

BaseMenu * FirstMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) {
	BaseMenu *aNewMenu = 0;
	switch (choice) {

		case 0:
		{
			std::cout<<"invalid choice"<<std::endl;
		}
		break;
		case 2:
		{
			aNewMenu = new SecondMenu;
		}
		break;
		case 3:
		{
			iIsQuitOptionSelected = true;
		}
		break;
		default:
		{
			// Do nothing - we won't change the menu
		}
	}
	return aNewMenu;
}

SecondMenu::SecondMenu() : BaseMenu(){
	m_MenuText = "OptionsMenu\n"
				 "Please make your selection\n"
				 "1 - return to main menu\n"
				 "2 - ha?";
}

BaseMenu * SecondMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) {
	BaseMenu *aNewMenu = 0;
	switch (choice)
	{
		case 1:
		{
			aNewMenu = new FirstMenu;
		}
		break;
		case 2:
		{
			aNewMenu = new FirstMenu;
		}
		break;

		default:
		{
			// Do nothing - we won't change the menu
		}
	}
	return aNewMenu;
}
