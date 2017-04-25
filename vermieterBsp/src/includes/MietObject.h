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
		unsigned int getOwner();
		unsigned int getRenter();
		void setOwner(unsigned int ownerId);
		void setRenter(unsigned int renterId);
		bool isAvailable();
		void setAv(bool);
		void setRate(double);
		double getRate();
		void setProfit(double);
		double getProfit();

	protected:
		double getPrize();
		void setPrize(double);
		double getSize();
		void setSize(double);
		const std::string& getAddress();
		void setAddress(const std::string &);

	private:
		bool isAv;
		double prize;
		double size;
		double monthlyRate;
		unsigned int ownerId;
		unsigned int renterId;
		std::string address;
};

//#endif
