// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 2 - Problem #7

/*
Initiaize millimeters, centimeters, meters
Ask user for millimeters
Convert to meters, find remainder of millimeters
Repeat for centimeters
Print values
*/

#include<iostream> //input/output stream

using namespace std;

int main() //main function
{
    int millimeters;
    int centimeters;
    int meters;
    
    cout << "Enter a number of millimeters:" << endl;
    cin >> millimeters;
    
    meters = millimeters / 1000;
    millimeters %= 1000; //millimeters = millimeters % 1000
    centimeters = millimeters / 10;
    millimeters %= 10;
    
    cout << meters << " meter(s) " << centimeters << " centimeter(s) " << millimeters << " millimeter(s) " << endl;
}