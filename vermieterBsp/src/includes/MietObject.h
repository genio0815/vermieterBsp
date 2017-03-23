/*
 * MietObject.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef SRC_INCLUDES_MIETOBJECT_H_
#define SRC_INCLUDES_MIETOBJECT_H_

#include <iostream>
#include <string>

class MietObject {
	public:
		MietObject();
		double getPrize() const;
		void setPrize(double prize);
		double getSize() const;
		void setSize(double size);
		const std::string& getAdress() const;
		void setAdress(const std::string& adress);

	protected:
		double prize;
		double size;
		std::string adress;
};


#endif
