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

// forward declarations
class Vermieter;
class Mieter;

class MietObject {
	public:
		MietObject(const std::string&, double, double);
		~MietObject() {};
		virtual void printToScreen();
		double getPrize() const;
		void setPrize(double prize);
		double getSize() const;
		void setSize(double size);
		const std::string& getAddress() const;
		void setAddress(const std::string& adress);
		Vermieter getOwner();
		Mieter getRenter();
		void setOwner(Vermieter own);
		void setRenter(Mieter rent);

	protected:
		double prize;
		double size;
		Vermieter owner();
		Mieter renter();
		std::string address;
};

//#endif
