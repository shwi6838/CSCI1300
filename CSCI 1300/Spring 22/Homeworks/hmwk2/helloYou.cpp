// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 2 - Problem #2

//Asks User for name
//Prints "Hello" and their name

#include<iostream> //input/output stream

using namespace std;

int main() //main function
{
    string name;
    cout << "Enter your name:" << endl;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    return 0;
}
