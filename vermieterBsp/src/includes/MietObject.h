///*
// * MietObject.h
// *
// *  Created on: Mar 22, 2017
// *      Author: alex
// */
//
//#ifndef SRC_INCLUDES_MIETOBJECT_H_
//#define SRC_INCLUDES_MIETOBJECT_H_
//

#pragma once

#include <iostream>
#include <string>
#include <vector>

// forward declarations
class Vermieter;
class Mieter;

class MietObject {
	public:
		MietObject();
		virtual ~MietObject() {};
		virtual void printToScreen();
		virtual void setProperties();
		virtual std::string csvLine();
		virtual void readProperties(std::vector<std::string> *) {};

	protected:
		double getPrize();
		void setPrize(double);
		double getSize();
		void setSize(double);
		const std::string& getAddress();
		void setAddress(const std::string &);
		Vermieter getOwner();
		Mieter getRenter();
		void setOwner(Vermieter own);
		void setRenter(Mieter rent);

	private:
		double prize;
		double size;
		Vermieter owner();
		Mieter renter();
		std::string address;
};

//#endif
