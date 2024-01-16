// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 4 - Problem 1

/*
Initialize input variable x and sum
Ask for value
Check negative bounds
Check every number between 0 and the value entered
If the value is divisible by 3 add it to the sum
Print the sum
*/

#include<iostream> 

using namespace std;

int main()
{
    int x;
    int sum=0;
    cout << "Enter a positive integer:" << endl;
    cin >> x;

    if(x<=0)
        cout << "Invalid input." << endl;

    else
    {
        for(int i =0; i <= x; i++)
        {
            if(i%3 == 0)
                sum +=i;
        }
        cout << "Sum: " << sum << endl;
    }
}