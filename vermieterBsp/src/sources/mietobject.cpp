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
	isAvailable = true;
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

	std::cout<<"is Available:\t"<<(isAvailable ? "Yes" : "NO")<<std::endl;
	std::cout<<"Addresse:\t"<<address<<std::endl;
	std::cout<<"Groesse:\t"<<size<<std::endl;
	std::cout<<"Preis:\t"<<prize<<std::endl;
}

void MietObject::setProperties() {

	address = Storage::checkString("enter Address");
	size = Storage::checkDouble("enter size");
	prize = Storage::checkDouble("enter prize");

	/*std::string token;

	if (Storage::persons.size() > 0) {
		token = Storage::checkString("to assign existing Vermieter enter: YES");
		if (token.compare("YES") == 0) {
			// just to check if valid index is entered
			std::vector<int> existingPersons;
			for (unsigned int i = 0; i< Storage::persons.size(); ++i) {
				existingPersons.push_back(int(i));
			}

	} else {
		token = Storage::checkString("to add a new flat enter: NEW\n(currently no flats present)\notherwise continue");
	}

	if (token.compare("NEW") == 0) {
		Storage::addFlat();
	} else if (token.compare("EX") == 0) {
		if (Storage::flats.size() > 0) {
			// just to check if valid index is entered
			std::vector<int> existingFlats;
			for (unsigned int i = 0; i< Storage::flats.size(); ++i) {
				existingFlats.push_back(int(i));
			}
			token = Storage::checkString("\nto list existing flats enter: YES");
			if (token.compare("YES") == 0) Storage::listFlats();
			int index = Storage::checkInt("enter flat ID",&existingFlats);
			Storage::flats.at(index)->setRenterPtr(std::make_shared<Mieter>(*this));
		}
	}
*/

	//TODO
	//ownerId = Storage::checkUInt("enter Vermieter Id");
	//renterId = Storage::checkUInt("enter Mieter Id");
}

std::string MietObject::csvLine() {

	std::string res;
	res = address +';' + std::to_string(isAvailable)+ ';'  + std::to_string(size) + ';' + std::to_string(prize);

	if (owner != nullptr) res += ';' + std::to_string(owner->getId());
	if (renter != nullptr) res +=  ';' + std::to_string(renter->getId());

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
    if (!isAvailable) {
        profit += monthlyRate * time;
        owner-> updateBalance(profit);
        renter-> updateBalance(profit);
        renter-> setMonthsInFlat(time);
    }
}
