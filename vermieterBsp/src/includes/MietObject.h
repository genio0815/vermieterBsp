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
		MietObject();
		double getPrize() const;
		void setPrize(double prize);
		double getSize() const;
		void setSize(double size);
		const std::string& getAdress() const;
		void setAdress(const std::string& adress);
		Vermieter getOwner();
		Mieter getRenter();
		void setOwner(Vermieter own);
		void setRenter(Mieter rent);

	protected:
		double prize;
		double size;
		Vermieter owner();
		Mieter renter();
		std::string adress;
};

//#endif
