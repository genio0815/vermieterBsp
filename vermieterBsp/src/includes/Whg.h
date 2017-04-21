//
// Created by Bindeus, Alexander on 4/20/17.
//

#ifndef SRC_INCLUDES_WHG_H
#define SRC_INCLUDES_WHG_H

#include "../includes/MietObject.h"

class Whg: public MietObject {
public:
	Whg();
    Whg(const std::string&, double, double);
    virtual ~Whg() {};
    void virtual printToScreen();
    const std::string& getCategory() const;
    void setCategory(const std::string& cat);
    void setProperties();

private:
    std::string category;
};

#endif
