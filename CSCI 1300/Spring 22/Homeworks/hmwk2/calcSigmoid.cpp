// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 2 - Problem #6

/*
Initialize variable int, sigmoid
Ask user for x
Use x to find sigmoid using equation
Print x and sigmoid
*/

#include<iostream> //input/output stream
#include <cmath>

using namespace std;

int main() //main function
{
    int x;
    double sigmoid;
    cout << "Enter a value for x:" << endl;
    cin >> x;

    sigmoid = 1 / (1+ exp(-x));
    cout << "The sigmoid for x="<<x<<" is "<<sigmoid<< endl;
}