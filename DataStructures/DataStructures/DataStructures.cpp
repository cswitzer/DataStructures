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

void ReferencePractice()
{
    // A reference is nothing more than giving another name to a variable
    // NOTE: references do not take up memory. This is why passing something in as
    // a reference saves memory, because passing in an object by reference
    // is the very act of passing in that object (even if it has a different name)
    // I am giving a another name: r
    int a = 10;
    int& r = a;

    // r does not become b!!! This means that a becomes 25, because r IS a
    int b = 25;
    r = b;

    // r is 30 to, because r is a
    a = 30;

    cout << a << endl;
    cout << r << endl;
}

void PointersToStructs()
{
    Rectangle r = { 10, 5 };
    Rectangle* p = &r;

    //p.length =20 will not work because p is a pointer; it has no variables!
    // (*p).length = 20 is hard to understand

    // Create struct pointer on the heap using C
    // Rectangle* p1 = (Rectangle*)malloc(sizeof(Rectangle));

    // create struct pointer in C++
    Rectangle* p1 = new Rectangle;
    p1->length = 10;
    p1->width = 20;

    cout << p1->length << endl;
    cout << p1->width << endl;
}

int add(int a, int b)
{
    int c = a + b;
    return c;
}

int incrementByTen(int a)
{
    // Hint, this function will not change the actual value of a
    return a += 10;
}

int incrementByTenReference(int& a)
{
    // this function will work!
    return a += 10;
}

void ValueVsReference()
{
    int num1 = 10, num2 = 42;
    int sum = add(num1, num2);
    cout << sum << endl;

    int incrementedNum1 = incrementByTen(num1);
    cout << incrementedNum1 << endl;
    // num1 has to be 20, right???!
    cout << num1 << endl;
    // wrong... a does not change because we incremented a COPY of a by 10

    // this does work, because incrementByTenReference's argument references a! This
    // means that IT IS a
    int incrementedNum1Reference = incrementByTenReference(num1);
    cout << incrementedNum1Reference << endl;
    cout << num1 << endl;
}

/// <summary>
/// Syntax in a parameter such as int *a means that we are passing in an address
/// to a variable. Syntax like int A[] means we are passing in a reference to an
/// array. If we are passing in a reference to an array, the only variable that can
/// store an address is a pointer, so "int A[]" IS a pointer to an array. You can also
/// write "int *A". However, if you specically want an array and not a general value,
/// we need to use "int A[]"
/// </summary>
void ArrFun(/* or "int *a" */int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

// this function returns a pointer (memory address variable) and stores it into
// another pointer (another memory address variable)
int * AnotherArrFun(int n)
{
    // This means that pointer B will get direct access to this function
    int *P = new int[n];
    for (int i = 0; i < n; i++)
    {
        P[i] = i + 1;
    }
    return P;
}

void ArrayPassingAndFunctionPointer()
{
    // passing an array as a parameter
    int A[5] = { 2,4,6,8,10 };
    // Arrays can never be passed by value, only by address
    ArrFun(A, 5);

    cout << endl;

    // function pointer
    int* B, size = 5;
    // Now B is accessing the array in the heap. P is already gone
    B = AnotherArrFun(size);
    for (int i = 0; i < size; i++)
    {
        cout << B[i] << endl;
    }
}

// call by address
int Area(Rectangle &r1)
{
    return r1.length * r1.width;
}

// this is the "call by address" in C code
void ChangeLength(Rectangle *r1)
{
    r1->length += 10;
    r1->width += 20;
}

/*
This is my main function
*/
int main()
{
    Rectangle  r = { 10,5 };
    int totalArea = Area(r);
    cout << totalArea << endl;

    ChangeLength(&r);
    cout << r.length << endl;
    cout << r.width << endl;
    return 0;
}