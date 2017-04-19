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
#include <memory> // for unique_ptr

#include "../includes/Storage.h"


class BaseMenu {
	public:
		BaseMenu();
		virtual ~BaseMenu() { }
		virtual std::unique_ptr<BaseMenu> getNextMenu(int iChoice, bool& iIsQuitOptionSelected) = 0;
		void printText();

	protected:
		std::vector<std::string> menuOptions;
		std::vector<std::string> *optPt;
};

class MainMenu : public BaseMenu {
	public:
		MainMenu();
		std::unique_ptr<BaseMenu> getNextMenu(int choice, bool& iIsQuitOptionSelected);
};

class PersonsMenu : public BaseMenu {
	public:
		PersonsMenu();
		std::unique_ptr<BaseMenu> getNextMenu(int choice, bool& iIsQuitOptionSelected);
};

class FlatsMenu : public BaseMenu {
	public:
		FlatsMenu();
		std::unique_ptr<BaseMenu> getNextMenu(int choice, bool& iIsQuitOptionSelected);
};

#endif
