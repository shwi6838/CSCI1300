// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 2 - Problem #4

/*
Initialize variables days
Initialize variables Breck, Copper, and Vail
Ask user for input days
Breck = 28 + 15(days) - 4(days)
Copper = 55 + 3(days) - 2(days)
Vail = 33 + 11(days) - 7(days)
Print each location value (estimates)
*/

#include<iostream> //input/output stream

using namespace std;

int main() //main function
{
    int days;
    int breck;
    int copper;
    int vail;

    cout << "How many days in the future would you like a prediction for?" << endl;
    cin >> days;
    
    breck = 28 + 15*days - 4*days;
    copper = 55 + 3*days - 2*days;
    vail = 33 + 11*days - 7*days;

    cout << "Breckenridge will have "<<breck<<" inches, Vail will have "<<vail<<" inches, and Copper Mountain will have "<<copper<<" inches." << endl;
}