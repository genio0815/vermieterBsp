/*
 * Menu.h
 *
 *  Created on: Mar 23, 2017
 *      Author: alex
 */

#ifndef SRC_INCLUDES_MENU_H_
#define SRC_INCLUDES_MENU_H_

#include <iostream>
#include <string>
#include <vector>

class BaseMenu {
	public:
		BaseMenu();
		virtual ~BaseMenu() { }
		virtual BaseMenu *getNextMenu(int iChoice, bool& iIsQuitOptionSelected) = 0;
		void printText();

//		virtual void printText() // This is made virtual, but doesn't *have* to be redefined. In the current code I have written, it is not redefined as we store the menu text as a string in the object
//		{
//			std::cout << m_MenuText << std::endl;
//		}

	protected:
		std::vector<std::string> menuOptions;
		std::vector<std::string> *optPt;
};

class MainMenu : public BaseMenu {
	public:
		MainMenu();
		BaseMenu *getNextMenu(int choice, bool& iIsQuitOptionSelected);
};

class PersonsMenu : public BaseMenu {
	public:
		PersonsMenu();
		BaseMenu *getNextMenu(int choice, bool& iIsQuitOptionSelected);
};

class FlatsMenu : public BaseMenu {
	public:
		FlatsMenu();
		BaseMenu *getNextMenu(int choice, bool& iIsQuitOptionSelected);
};

#endif
