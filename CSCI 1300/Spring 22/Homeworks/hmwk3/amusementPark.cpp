// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 3 - Problem #2

/*
Initialize height and character for switch choice
Ask for height (in)
Check for negative bounds
Ask for ride choice
For each choice, check height
Check for invalid choice
*/

#include<iostream> //input/output stream

using namespace std;

int main() //main function
{
    double height;
    char x;
    cout << "How tall are you in inches?" << endl;
    cin >> height;

    if (height < 0.0)
    {
        cout << "Please enter a valid input." << endl;
    }
    else
    {
        cout << "What ride would you like to take(c, t, or i)?" << endl;
        cin >> x;

        switch (x)
        {
            case 'c':
            if (height >= 30.0)
            {
                cout << "Yes, you are allowed to go on that ride!" << endl;
            }
            else
            {
                cout << "Sorry, you cannot go on that ride." << endl;
            }
            break;
            case 't':
            if (height >= 36.0)
            {
                cout << "Yes, you are allowed to go on that ride!" << endl;
            }
            else
            {
                cout << "Sorry, you cannot go on that ride." << endl;
            }
            break;
            case 'i':
            if (height >= 45.0)
            {
                cout << "Yes, you are allowed to go on that ride!" << endl;
            }
            else
            {
                cout << "Sorry, you cannot go on that ride." << endl;
            }
            break;
            default:
            cout << "Please enter a valid input." << endl;
            break;
        }
    }
}