/*
 * myMain.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: alex
 */



//#include <iostream>
//#include <string>
//#include <vector>

#include "header/Person.h"
#include "header/Vermieter.h"
#include "header/Mieter.h"
#include "header/MietObject.h"
#include "header/Haus.h"

using namespace std;

int main() {
	cout<<"vermieter bsp"<<endl;

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



