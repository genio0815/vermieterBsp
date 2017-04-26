/*
 * Haus.h
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#ifndef SRC_INCLUDES_HAUS_H_
#define SRC_INCLUDES_HAUS_H_

#include<vector>

#include "../includes/MietObject.h"

class Haus: public MietObject {
	public:
		Haus();
		virtual ~Haus(){};
		virtual void printToScreen();
		virtual std::string csvLine();
		virtual void readProperties(std::vector<std::string> *);
		void setProperties();

	private:
		unsigned int floors;
		bool hasCellar;
		std::string constructionDate;
};

#endif
