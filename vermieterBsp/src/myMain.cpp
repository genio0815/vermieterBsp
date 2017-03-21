/*
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

		Person(){}

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
};

class Mieter: protected Person {
	public:
		Mieter(const std::string& name, unsigned int age) : Person(name,age) {
			cout<<"doe"<<endl;
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

	private:
		double expenses;
};

int main() {
	cout<<"vermieter bsp"<<endl;

	Person test2("hugo",42);
	test2.printToScreen();

	Vermieter test1("heinzi",45);
	test1.printToScreen();

	return 0;
}



