#pragma once
#include <iostream>
#include <memory>

using namespace std;

// pure virtual function "printName()" makes this class abstract
class Animal {
public:
	virtual void printName() = 0;
	virtual void printAge() = 0;

	virtual ~Animal();
};

class Dog : public Animal {
private:
	string dogName;
	int dogAge;
public:
	Dog(const string& name, const int age)
		: dogName(name), dogAge(age){}

	void printName() override;
	void printAge() override;

	~Dog();
};

/*
void PracticeSmartPointers()
{
    Dog dog1("Max", 10);
    dog1.printName();
    dog1.printAge();

    Dog dog2("Spot", 4);
    dog2.printName();
    dog2.printAge();

    Animal* a;
    a = &dog1;
    Animal* b;
    b = &dog2;

    a->printName();
    a->printAge();
    b->printName();
    b->printAge();

    // unique pointers can only point to one block of memory, and are freed after program ends
    // You cannot copy using this pointer though!
    // same as Dog *dog = new Dog("Poochyena", 4), and calling delete after
    std::unique_ptr<Dog> dogUnique = std::make_unique<Dog>("Poochyena", 4);
    dogUnique->printName();
    dogUnique->printAge();

    // This copy constructor will not work because dogUnique is unique. Another reference
    // will free the referenced memory and there will be nothing to copy
    // unique_ptr<Dog> dogUniqueTwo = dogUnique;

    // sharing is caring. Use share pointers
    std::shared_ptr<Dog> dogShared = make_shared<Dog>("Growlithe", 1);
    shared_ptr<Dog> dogSharedTwo = dogShared; // this will increase the ref count
    std::weak_ptr<Dog> dogSharedThree = dogShared; // does not increase ref count


    // without smart pointers
    Dog* dogNotUnique = new Dog("Mightyena", 4);
    delete dogNotUnique;
}
*/