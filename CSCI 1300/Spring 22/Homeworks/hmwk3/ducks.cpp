// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 3 - Problem #3

/*
Initialize ducks and cost
Ask user for number of ducks
Check for bounds (-)
Calculate initial cost for number of ducks 
Read how many ducks and determine discount with if statements
Apply discounts using decimal multiplication
Output new cost
*/

#include<iostream> //input/output stream
#include<iomanip>
using namespace std;

int main() //main function
{
    int ducks;
    double cost;
    cout << "How many ducks would you like to order?" << endl;
    cin >> ducks;

    if (ducks < 0)
    {
        cout << "Please enter a valid input." << endl;
    }
    else
    {
        cout << (fixed) << setprecision(2);
        cost = double(ducks) * .50;
        
        if(ducks <= 20)
        {
            cost = cost;
        }
        else if(ducks > 20 && ducks <= 100)
        {
            cost *= .90;
        }
        else if(ducks > 100 && ducks <= 500)
        {
            cost *= .80;
        }
        else
        {
            cost *= .50;
        }

        cout << "Your total is $" << cost << endl;
    }
}