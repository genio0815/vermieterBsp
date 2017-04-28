/*
 * mietobject.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: alex
 */

#include "../includes/MietObject.h"
#include "../includes/Storage.h"

MietObject::MietObject() {
	owner = nullptr;
	renter = nullptr;
	prize = 0.0;
	size = 0.0;
	profit = 0.0;
	monthlyRate = 0.0;
}

std::string MietObject::getAddress() {
	return address;
}

void MietObject::printToScreen() {

	if (owner != nullptr)
		std::cout<<"Vermieter:\t"<<owner->getName()<<std::endl;
	else
		std::cout<<"Vermieter:\t"<<"NONE"<<std::endl;

	if (renter != nullptr)
		std::cout<<"Mieter:\t"<<renter->getName()<<std::endl;
	else
		std::cout<<"Mieter:\t"<<"NONE"<<std::endl;

	std::cout<<"Addresse:\t"<<address<<std::endl;
	std::cout<<"Groesse:\t"<<size<<std::endl;
	std::cout<<"Preis:\t"<<prize<<std::endl;
	std::cout<<"monatl. Miete\t"<<monthlyRate<<std::endl;
}

void MietObject::setProperties() {

	unsigned int i;
	std::string token;

	// change 2804: new MieterObject HAS to be associated to a Vermieter

	std::cout<<"new flats have to be assigned to a owner\n"<<std::endl;
	token = Storage::checkString("to assign to existing owner enter YES, else create a new owner");

	if (token.compare("YES") == 0) {
		if (Storage::persons.size() > 0) {
			std::vector<unsigned int> existingVermieters;
			std::cout<<"existing Owners:\n"<<std::endl;
			for (i = 0; i< Storage::persons.size(); ++i) {
				if(Storage::persons.at(i)->getType()) {
					existingVermieters.push_back(i);
					std::cout<<Storage::persons.at(i)-> getName()<<std::endl;
				}
			}
			if (existingVermieters.size() == 0) {
				std::cout<<"currently no owners present - returning\n"<<std::endl;
				return;
			} else {
				std::cout<<"available owners:\n"<<std::endl;
				for (i = 0; i< existingVermieters.size();++i) {
					std::cout<<"ID: "<<i<<' '<<Storage::persons.at(i)->getName()<<std::endl;
				}
				i = Storage::checkUInt("enter ID of owner", &existingVermieters);
				owner = std::static_pointer_cast<Vermieter>(Storage::persons.at(i));
			}
		} else {
			std::cout<<"no owners present - returning\n"<<std::endl;
			return;
		}
	} else {
		std::cout<<"creating new owner, who will be assigned to flat"<<std::endl;
		Storage::persons.push_back(std::make_shared<Vermieter>());
		Storage::persons.back()->setId(Storage::persons.size()-1);
		Storage::persons.back()->setProperties();
		std::cout<<"\nproceeding with flat properties !!!\n"<<std::endl;
		owner = std::static_pointer_cast<Vermieter>(Storage::persons.back());
	}

	address = Storage::checkString("enter Address");
	size = Storage::checkDouble("enter size");
	prize = Storage::checkDouble("enter prize");
	monthlyRate = Storage::checkDouble("enter monthly rate:");
}

std::string MietObject::csvLine() {

	std::string res;
	res = address +',' + std::to_string(size) + ',' + std::to_string(prize) + ',' + std::to_string(monthlyRate);

	if (owner != nullptr)
		res += ',' + std::to_string(owner->getId());
	else
		res += ",NONE";

	if (renter != nullptr)
		res +=  ',' + std::to_string(renter->getId());
	else
		res += ",NONE";

	return res;
}

std::shared_ptr<Mieter> MietObject::getRenterPtr() {
	return renter;
}
std::shared_ptr<Vermieter> MietObject::getOwnerPtr() {
	return owner;
}

void MietObject::setRenterPtr(std::shared_ptr<Mieter> rent) {
	this->renter = rent;
}
void MietObject::setOwnerPtr(std::shared_ptr<Vermieter> own) {
	this->owner = own;
}

void MietObject::updateProfit(double time){
    if (renter != nullptr) {
        profit += monthlyRate * time;
        owner-> updateBalance(profit);
        renter-> updateBalance(profit);
        renter-> setMonthsInFlat(time);
    }
}
