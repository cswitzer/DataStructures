#include <iostream>
#include "OOPPractice.h"

using namespace std;

void Dog::printName()
{
	cout << "The animal's name is: " << dogName << endl;
}

void Dog::printAge()
{
	cout << "The dog's age is " << dogAge << endl;
}

Animal::~Animal()
{
	cout << "Animal Destructor Called." << endl;
}

Dog::~Dog()
{
	cout << "Dog Destructor Called." << endl;
}