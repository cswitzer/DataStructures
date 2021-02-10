// DataStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <string>
using namespace std;

/*
This section deals with structs
*/
struct Rectangle
{
    // is taking up 16 bytes of memory
    float length;
    float width;
};

struct Complex
{
    int real;
    int img;
};

struct Student
{
    int roll;
    int age;
    string name;
    string department;
    string address;
    string phoneNumber;
};

struct Card
{
    int faceValue;
    int shape;
    int color;
};




/*
This is my main function
*/
int main()
{
    const int n = 6;
    std::array<int, 5> A;
    A[0] = 10;
    A[1] = 10;
    A[2] = 10;
    A[3] = 10;
    A[4] = 10;

    cout << "Size of int array: " << A.size() << endl;

    Rectangle r1;
    r1.length = 10;
    r1.width = 10;
    cout << "Area of rectangle: " << r1.length * r1.width << endl;

    Student s1;
    s1.name = "Chase";
    s1.age = 21;

    Card c;
    c.shape = 0;
    c.color = 0;
    c.color = 0;

    Card deck[52] = { { 1,0,0 }, { 2,2,2 }, { 1,1,1 } };
    cout << deck[0].faceValue << endl;
    cout << deck[0].shape << endl;
    cout << deck[0].color << endl;

    return 0;
}