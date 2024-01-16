// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 4 - Problem 2

/*
Initialize input variable a
Ask user for input 
Check for negative bounds
Print the input
If the value is even, print the square root of a
If the value is odd, print the root of a to the power of 3
Keep going until the value is equal to 1
*/

#include<iostream> 
#include<cmath>

using namespace std;

int main()
{
    long int a;
    cout << "Enter a positive integer:" << endl;
    cin >> a;

    if(a<=0)
        cout << "Invalid input." << endl;

    else
    {
        cout << a << endl;
        while (a > 1)
            if(a%2 == 0)
            {
                a = floor(sqrt(a));
                cout << a << endl;
            }
            else
            {
                a = floor(pow(sqrt(a),3));
                cout << a << endl;
            }
    }
}