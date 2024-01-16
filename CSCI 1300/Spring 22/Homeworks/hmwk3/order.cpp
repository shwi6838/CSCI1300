// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 3 - Problem #5

/*
Initialize choices 1-3, cost
Ask user for first bracket of choices
Use switch statements and ask again for more specific choices
Use switch statements again to ask for specific order
Each choice will update the total cost of the order, by including in case statements
Calculate cost/add-ons and output cost
Check for bounds/invalid choices
*/

#include<iostream> //input/output stream
#include<iomanip>
using namespace std;

int main() //main function
{
    int choice;
    int choice2;
    int choice3;
    double cost;
    cout << (fixed) << setprecision(2);
    cout << "What would you like? 1.Drink 2.Meal 3.Dessert" << endl;
    cin >> choice;
    switch (choice)
    {
        case 1:
        cost = 3.00;
        cout << "Select one: 1.Boba 2.Soda" << endl;
        cin >> choice2;
        switch (choice2)
        {
            case 1:
            cost += 2.00;
            cout << "Select one: 1.Tapioca 2.Popping 3.Crystal" << endl;
            cin >> choice3;
            switch (choice3)
            {
                case 1:
                cost = cost;
                cout << "Order total is $" << cost << endl;
                break;
                case 2:
                cost +=1.50;
                cout << "Order total is $" << cost << endl;
                break;
                case 3:
                cost +=1.50;
                cout << "Order total is $" << cost << endl;
                break;
                default:
                cout << "Please enter a valid input." << endl;
                break;
            }
            break;
            case 2:
            cout << "Select one: 1.Sprite 2.Coke" << endl;
            cin >> choice3;
            switch (choice3)
            {
                case 1:
                cost = cost;
                cout << "Order total is $" << cost << endl;
                break;
                case 2:
                cost = cost;
                cout << "Order total is $" << cost << endl;
                break;
                default:
                cout << "Please enter a valid input." << endl;
                break;
            }
            default:
            cout << "Please enter a valid input." << endl;
            break;
        }
        break;
        case 2:
        cost = 10.00;
        cout << "Select one: 1.Tacos 2.Burger" << endl;
        cin >> choice2;
        switch (choice2)
        {
            case 1:
            cout << "Select one: 1.Pork 2.Chicken" << endl;
            cin >> choice3;
            switch (choice3)
            {
                case 1:
                cost = cost;
                cout << "Order total is $" << cost << endl;
                break;
                case 2:
                cost = cost;
                cout << "Order total is $" << cost << endl;
                break;
                default:
                cout << "Please enter a valid input." << endl;
                break;
            }
            break;
            case 2:
            cost += 2.50;
            cout << "Select one: 1.Cheeseburger 2.Veggie Burger" << endl;
            cin >> choice3;
            switch (choice3)
            {
                case 1:
                cost = cost;
                cout << "Order total is $" << cost << endl;
                break;
                case 2:
                cost +=2.00;
                cout << "Order total is $" << cost << endl;
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
        break;
        case 3:
        cost = 6.50;
        cout << "Select one: 1.Ice Cream 2.Cookies 3.Cake" << endl;
        cin >> choice2;
        switch (choice2)
        {
            case 1:
            cout << "Select one: 1.Rocky Road 2.Vanilla" << endl;
            cin >> choice3;
            switch (choice3)
            {
                case 1:
                cost +=.50;
                cout << "Order total is $" << cost << endl;
                break;
                case 2:
                cost = cost;
                cout << "Order total is $" << cost << endl;
                break;
                default:
                cout << "Please enter a valid input." << endl;
                break;
            }
            break;
            case 2:
            cout << "Select one: 1.Chocolate Chip 2.Snickerdoodle" << endl;
            cin >> choice3;
            switch (choice3)
            {
                case 1:
                cost = cost;
                cout << "Order total is $" << cost << endl;
                break;
                case 2:
                cost = cost;
                cout << "Order total is $" << cost << endl;
                break;
                default:
                cout << "Please enter a valid input." << endl;
                break;
            }
            break;
            case 3:
            cost += 2.00;
            cout << "Select one: 1.Tiramisu 2.Cheesecake" << endl;
            cin >> choice3;
            switch (choice3)
            {
                case 1:
                cost += 1.00;
                cout << "Order total is $" << cost << endl;
                break;
                case 2:
                cost = cost;
                cout << "Order total is $" << cost << endl;
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
        break;
        default:
        cout << "Please enter a valid input." << endl;
        break;
    }
}