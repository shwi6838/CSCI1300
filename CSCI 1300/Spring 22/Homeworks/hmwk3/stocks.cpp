// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 3 - Problem #4

/*
Initialize int x,y,z
Ask user for 3 stock values
Check for bounds (-)
Check for if x > y > z  (tanking)
Check for if x < y < z  (rising)
Else statment for any other case (neither)
*/

#include<iostream> //input/output stream
#include<iomanip>
using namespace std;

int main() //main function
{
    double x;
    double y;
    double z;
    cout << "Enter stock prices over last 3 weeks" << endl;
    cin >> x;
    cin >> y;
    cin > z;

    if(x < 0.0 || y < 0.0 || z < 0.0)
    {
        cout << "Please enter a valid input." << endl;
    }
    else
    {
        if((x > y) && (y > z))
        {
                cout << "The value is tanking." << endl;
        }
        else if((z > y) && (y > x))
        {
                cout << "The value is rising!" << endl;
        }
        else
        {
            cout << "Neither" << endl;
        }
    }
}