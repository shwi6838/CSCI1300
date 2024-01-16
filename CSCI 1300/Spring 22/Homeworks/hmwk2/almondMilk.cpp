// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 2 - Problem #3

/*
Initialize variables side and height and volume and ounces
Ask for input for side length and height in inches
Volume = side multiplied by side multiplied by height
Ounces = 0.55 times volume
Print ounces
*/

#include<iostream> //input/output stream
#include<iomanip>
using namespace std;

int main() //main function
{
    int side;
    int height;
    double area;
    double ounces;

    cout << "What is the side length of the base of the carton in inches? " << endl;
    cin >> side;
    cout << "What is the height of the carton in inches?" << endl;
    cin >> height;
    area = side * side;
    cout << (fixed) << setprecision(2);
    ounces = area*height* 0.55;
    cout << "The carton has a volume of " << ounces << " ounces." << endl;
}