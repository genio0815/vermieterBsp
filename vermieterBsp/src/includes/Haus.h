/*
 * Haus.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef SRC_INCLUDES_HAUS_H_
#define SRC_INCLUDES_HAUS_H_

#include "../includes/MietObject.h"

class Haus: public MietObject {
	public:
		Haus();
		const std::string& getConstuctionDate() const;
		void setConstuctionDate(const std::string& constuctionDate);
		unsigned int getFloors() const;
		void setFloors(unsigned int floors);
		bool isHasCellar() const;
		void setHasCellar(bool hasCellar);

	private:
		unsigned int floors;
		bool hasCellar;
		std::string constuctionDate;
};

#endif