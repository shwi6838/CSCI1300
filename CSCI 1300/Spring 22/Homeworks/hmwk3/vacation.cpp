// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 3 - Problem #6

/*
Initialize choices 1-2, cost
Ask for country
Use switch commands and at each case s for a city in that country
Use switch commands to choose a city and output travel cost
Check for bounds/invalid choices
*/

#include<iostream> //input/output stream
#include<iomanip>
using namespace std;

int main() //main function
{
    int choice;
    int choice2;
    int cost;

    cout << "Enter country: 1.South Africa 2.Mexico 3.India 4.Costa Rica" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
        cout << "Enter city: 1.Capetown 2.Johannesburg" << endl;
        cin >> choice2;
        switch(choice2)
        {
            case 1:
            cost = 1200;
            cout << "Your trip will be $" << cost << "." << endl;
            break;
            case 2:
            cost = 1000;
            cout << "Your trip will be $" << cost << "." << endl;
            break;
            default:
            cout << "Please enter a valid input." << endl;
            break;
        }
        break;
        case 2:
        cout << "Enter city: 1.Cancun 2.Mexico City" << endl;
        cin >> choice2;
        switch(choice2)
        {
            case 1:
            cost = 950;
            cout << "Your trip will be $" << cost << "." << endl;
            break;
            case 2:
            cost = 800;
            cout << "Your trip will be $" << cost << "." << endl;
            break;
            default:
            cout << "Please enter a valid input." << endl;
            break;
        }
        break;
        case 3:
        cout << "Enter city: 1.Manali 2.Kochi" << endl;
        cin >> choice2;
        switch(choice2)
        {
            case 1:
            cost = 1100;
            cout << "Your trip will be $" << cost << "." << endl;
            break;
            case 2:
            cost = 900;
            cout << "Your trip will be $" << cost << "." << endl;
            break;
            default:
            cout << "Please enter a valid input." << endl;
            break;
        }
        break;
        case 4:
        cout << "Enter city: 1.San Jose 2.San Vicente" << endl;
        cin >> choice2;
        switch(choice2)
        {
            case 1:
            cost = 800;
            cout << "Your trip will be $" << cost << "." << endl;
            break;
            case 2:
            cost = 1300;
            cout << "Your trip will be $" << cost << "." << endl;
            break;
            default:
            cout << "Please enter a valid input." << endl;
            break;
        }
        break;
        default:
        cout << "Please enter a valid input." << endl;
        break;
    }
}