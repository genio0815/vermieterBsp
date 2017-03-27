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
		BaseMenu();// This is the constructor - we use it to set class-specific information. Here, each menu object has its own menu text.
		virtual ~BaseMenu() { } // This is the virtual destructor. It must be made virtual, else you get memory leaks - it's not a quick explaination, I recommend you read up on it
		virtual BaseMenu *getNextMenu(int iChoice, bool& iIsQuitOptionSelected) = 0; // This is a 'pure virtual method', as shown by the "= 0". It means it doesn't do anything. It's used to set up the framework
		void printText(std::vector<std::string> menuChoi); // This is made virtual, but doesn't *have* to be redefined. In the current code I have written, it is not redefined as we store the menu text as a string in the object

		virtual void printText() // This is made virtual, but doesn't *have* to be redefined. In the current code I have written, it is not redefined as we store the menu text as a string in the object
				{
					std::cout << m_MenuText << std::endl;
		}

	protected:
		std::vector<std::string> menuChoi;
		std::string m_MenuText; // This string will be shared by all children (i.e. derived) classes
};

class FirstMenu : public BaseMenu {// We're saying that this FirstMenu class is a type of BaseMenu
	public:
		FirstMenu();
		BaseMenu *getNextMenu(int choice, bool& iIsQuitOptionSelected);
};

class SecondMenu : public BaseMenu {
	public:
		SecondMenu();
		BaseMenu *getNextMenu(int choice, bool& iIsQuitOptionSelected);
};

#endif
