// DataStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <string>
#include <stdlib.h>
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
Just a function to practice instantiating structs with. Nothing callable really
*/
void StructObjects()
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
}

void PointerPractice()
{
    // Pointers are address data that stores ADDRESS DATA
    // 1. One of the main purposes of a pointer is to allocate and use data on the heap
    // 2. Another main purpose is accessing resources outside of a program
    // 3. Used for passing parameters
    // Example: if we wanted to access data from an external program, we would need
    // a pointer because external programs do not exist in our program directly

    int a = 10;
    int* p = &a; // 'p' is a pointer variable that holds the address of 'a'

    cout << *p << endl;
    cout << a << endl;

    // allocating heap memory in c
    int* p2 = (int*)malloc(5 * sizeof(int));
    // allocating heap memory in c++
    int* p3 = new int[5];

    int A[5] = { 1,2,3,4,5 };
    int* p4;
    p4 = A; // optionally, p4 = &A[0], but not &A
    /*for (int i = 0; i < 5; i++)
    {
        cout << p4[i] << endl;
    }*/

    // assigning array in the heap
    int* p5 = new int[5];
    p5[0] = 1;
    p5[1] = 2;
    p5[2] = 3;
    p5[3] = 4;
    p5[4] = 5;

    for (int j = 0; j < 5; j++)
    {
        cout << p5[j] << endl;
    }

    // we finished using the data in the heap, so we get rid of it
    delete[]p2;
    delete[]p3;
    delete[]p5;
    // freeing memory in C
    // free(p5);
}

/*
This is my main function
*/
int main()
{
    // A reference is nothing more than giving another name to a variable
    // I am giving a another name: r
    int a = 10;
    int &r = a;

    cout << a << endl;
    cout << r << endl;

    return 0;
}