// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 3 - Problem #1

/*
Initialize variables age
Ask user for age
Check for negative bound
If age is over or equal to 18, let them get a ticket
If age is under 18, tell them they cannot
*/

#include<iostream> //input/output stream

using namespace std;

int main() //main function
{
    int age;
    cout << "How old are you?" << endl;
    cin >> age;

    if (age < 0)
    {
        cout << "Please enter a valid input." << endl;
    }
    else
    {
        if(age < 18)
        {
            cout << "You cannot buy a lottery ticket yet." << endl;
        }
        else
        {
            cout << "You can buy a ticket! Good luck." << endl;
        }
    }
}