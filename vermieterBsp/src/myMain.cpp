/*
 * myMain.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: alex
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
	public:
		Person(const std::string& name, unsigned int age){
			setName(name);
			setAge(age);
		}

		void printToScreen() const {
			cout<<"name:\t"<<getName()<<endl;
			cout<<"age:\t"<<getAge()<<endl;
		}

		unsigned int getAge() const {
			return age;
		}

		void setAge(unsigned int age) {
			this->age = age;
		}

		const string& getName() const {
			return name;
		}

		void setName(const string& name) {
			this->name = name;
		}

	private:
		string name;
		unsigned int age;
};

class Vermieter: protected Person {
	public:
		Vermieter(const std::string& name, unsigned int age) : Person(name,age) {
			income = 0.0;
		}

		double getIncome() const {
			return income;
		}

		void setIncome(double income) {
			this->income = income;
		}

		void printToScreen() const {
			Person::printToScreen();
			cout<<"income:\t"<<getIncome()<<endl;
		}

	private:
		double income;
		//vector<MietObject> ownedFlats;
};

class Mieter: protected Person {
	public:
		Mieter(const std::string& name, unsigned int age) : Person(name,age) {
			expenses = 0.0;
		}

		double getExpenses() const {
			return expenses;
		}

		void setExpenses(double expenses) {
			this->expenses = expenses;
		}

		void printToScreen() const {
			Person::printToScreen();
			cout<<"expenses:\t"<<getExpenses()<<endl;
		}

	const string& getMovingInDate() const {
		return movingInDate;
	}

	void setMovingInDate(const string& movingInDate) {
		this->movingInDate = movingInDate;
	}

	private:
		double expenses;
		string movingInDate;
};

class MietObject {
	public:
		double getPrize() const {
			return prize;
		}

		void setPrize(double prize) {
			this->prize = prize;
		}

		double getSize() const {
			return size;
		}

		void setSize(double size) {
			this->size = size;
		}

	const string& getAdress() const {
		return adress;
	}

	void setAdress(const string& adress) {
		this->adress = adress;
	}

	protected:
		double prize;
		double size;
		string adress;

};

class Haus: MietObject {
public:
	const string& getConstuctionDate() const {
		return constuctionDate;
	}

	void setConstuctionDate(const string& constuctionDate) {
		this->constuctionDate = constuctionDate;
	}

	unsigned int getFloors() const {
		return floors;
	}

	void setFloors(unsigned int floors) {
		this->floors = floors;
	}

	bool isHasCellar() const {
		return hasCellar;
	}

	void setHasCellar(bool hasCellar) {
		this->hasCellar = hasCellar;
	}

	private:
		unsigned int floors;
		bool hasCellar;
		string constuctionDate;
};


int main() {
	cout<<"vermieter bsp"<<endl;

	Person test2("hugo",42);
	test2.printToScreen();

	Vermieter test1("heinzi",45);
	test1.printToScreen();

	return 0;
}



