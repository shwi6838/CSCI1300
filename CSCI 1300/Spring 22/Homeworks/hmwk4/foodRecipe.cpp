// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 4 - Problem 3

/*
Present a menu
Read input
Use switch chain to determine sandwich
Ask for each amount of ingredient that the user has for its corresponding sandwich
Determine with if statements if they can make the sandwich
Check for bounds
*/

#include<iostream>

using namespace std;


int main()
{
    bool stop = 0;
    while (stop == 0)
    {
        int choice;
        cout << "Select a numerical option:" << endl;
        cout << "=== menu ===" << endl;
        cout << "1. BLT sandwich" << endl;
        cout << "2. Caprese sandwich" << endl;
        cout << "3. Veggie sandwich" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
            int bacon,tomato,lettuce;
            double mayo;
            cout << "How many bacon strips do you have?" << endl;
            cin >> bacon;
            cout << "How many tomato slices do you have?" << endl;
            cin >> tomato;
            cout << "How many lettuce leaves do you have?" << endl;
            cin >> lettuce;
            cout << "How many ounces of mayonnaise do you have?" << endl;
            cin >> mayo;

            if((bacon >= 4) && (tomato >= 3) && (lettuce >=2) && (mayo >=0.51))
                cout << "You can make a BLT sandwich." << endl;
            else
                cout << "You don't have enough for a BLT sandwich." << endl;
            break;
            case 2:
            int mozzarella,tomato,basil;
            double balsamic;
            cout << "How many mozzarella slices do you have?" << endl;
            cin >> mozzarella;
            cout << "How many tomato slices do you have?" << endl;
            cin >> tomato;
            cout << "How many basil leaves do you have?" << endl;
            cin >> basil;
            cout << "How many ounces of balsamic glaze do you have?" << endl;
            cin >> balsamic;

            if((mozzarella >= 4) && (tomato >= 2) && (basil >=9) && (balsamic >=0.12))
                cout << "You can make a Caprese sandwich." << endl;
            else
                cout << "You don't have enough for a Caprese sandwich." << endl;
            break;
            case 3:
            int onion,cucumber;
            double pepper, hummus;
            cout << "How many red onion rings do you have?" << endl;
            cin >> onion;
            cout << "How many cucumber slices do you have?" << endl;
            cin >> cucumber;
            cout << "How many ounces of diced roasted pepper do you have?" << endl;
            cin >> pepper;
            cout << "How many ounces of hummus do you have?" << endl;
            cin >> hummus;

            if((onion >= 5) && (cucumber >= 7) && (pepper >=2.33) && (hummus >=2.5))
                cout << "You can make a Veggie sandwich." << endl;
            else
                cout << "You don't have enough for a Veggie sandwich." << endl;
            break;
            case 4:
            cout << "Goodbye!" << endl;
            stop = 1;
            break;
            default:
            cout << "Invalid input." << endl;
            break;
        }
    }
}