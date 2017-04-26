//
// Created by Bindeus, Alexander on 4/20/17.
//

#ifndef SRC_INCLUDES_WHG_H
#define SRC_INCLUDES_WHG_H

#include "../includes/MietObject.h"

class Whg: public MietObject {
public:
	Whg();
    virtual ~Whg() {};
    void virtual printToScreen();
    virtual std::string csvLine();
    virtual void setProperties();
    virtual void readProperties(std::vector<std::string> *);

private:
    std::string category;
};

#endif
