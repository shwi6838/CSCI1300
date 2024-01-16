// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 4 - Problem 5

/*
Initialize height
Ask for height
Check for negative bound
Create rows using a for loop
In each row print a character of the alphabet in order
  -> Each row will get smaller, starting at the height number to create a triangle shape
When the character hits 'z' it restarts at 'a'
Finishes on the last row with one character
*/

#include<iostream>

using namespace std;

int main()
{
    int height;
    cout << "Enter the height:" << endl;
    cin >> height;

    if(height <= 0)
        cout << "Invalid input." << endl;

    else
    {
        int i,j, n = height;
        char c = 'a';
        for (i = 0; i <= n; i++)
        {
            for (j=n-i-1; j >=0; j--)
            {
                if(c == ('z'+1))
                {
                    c = 'a';
                }
                cout<<c;
                c++;
            }
            cout << endl;
        }
    }
}