// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 2 - Problem #5

/*
Initialize knut, sickle, galleon
Ask user for knuts
Convert to sickles, find remainder of knuts
Convert to galleons, find remainder of sickles
Print values
*/

#include<iostream> //input/output stream

using namespace std;

int main() //main function
{
    int knut;
    int sickle;
    int galleon;

    cout << "Enter the number of Knuts:" << endl;
    cin >> knut;

    sickle = knut / 29;
    knut %= 29;
    galleon = sickle / 17;
    sickle %= 17;

    cout <<galleon<<" Galleon(s) "<<sickle<<" Sickle(s) "<<knut<<" Knut(s)" << endl;
}