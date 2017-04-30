///*
// * MietObject.h
// *
// *  Created on: Mar 22, 2017
// *      Author: alex
// */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "../includes/Person.h"
#include "../includes/Vermieter.h"
#include "../includes/Mieter.h"

// forward declarations
//class Vermieter;
//class Mieter;

class MietObject {
	public:
		MietObject();
		virtual ~MietObject() {};
		virtual void printToScreen();
		virtual void setProperties();
		virtual std::string csvLine();
		virtual void readProperties(std::vector<std::string> *, unsigned int) = 0;

        void updateProfit(double);
        std::string getAddress();

        void setRenterPtr(std::shared_ptr<Mieter>);
        void setOwnerPtr(std::shared_ptr<Vermieter>);
        std::shared_ptr<Mieter> getRenterPtr();
        std::shared_ptr<Vermieter> getOwnerPtr();

	protected:
		std::string address;
		double prize;
		double size;
		double monthlyRate;
        double profit;

        std::shared_ptr<Mieter> renter;
        std::shared_ptr<Vermieter> owner;
};
