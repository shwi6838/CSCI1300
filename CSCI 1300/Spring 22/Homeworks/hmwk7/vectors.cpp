// CSCI 1300 Spring 2022
// Author: Shane Wierl
// Recitation: 105 – Tiffany Phan
// Homework 7 - Problem #3

#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    vector <int> vec1; //Initialize vector of strings
    int run = 0; 
    while(run == 0) //Create a int/bool to keep program running
    {
        int input;
        cout << "Please enter a number:" << endl; //Ask user for number
        cin >> input;

        if(input == -1) //If input is -1 stop code and while loop
        {
            run = -1;
            break;
        }

        if(input <= 0) //Check for negative inputs
        {
            cout << "The number should be a positive integer or -1." << endl;
        }

        if(vec1.empty()==true) //If vector is empty add input to start vector
        {
            vec1.push_back(input);
        }
        else //If vector has elements
        {
            if(input %5 == 0) //If input divisible by 5 take away the first term
            {
                vec1.erase(vec1.begin());
            }
            else if(input %3 == 0) //If input divisible by 3 take term from end
            {
                vec1.pop_back();
            }
            else //Other numbers
            {
                vec1.push_back(input); //Add to vector
            }
        }
    }

        if(vec1.empty()==true) //Check for empty vector
            cout << "The vector is empty." << endl;
        else
        {
            int min= 10000000;
            int max= 0;
            cout << "The elements in the vector are:"; //List the vectors elements in order
            for(int i = 0; i < vec1.size(); i++)
            {
                cout << " ";
                cout << vec1[i]; //Print element
                if(vec1[i] < min) //Check and find min value
                    min = vec1[i];
                if((vec1[i] > max) && (vec1[i] >= min)) //Check and find max value
                    max = vec1[i];
            }
            cout << endl;
            cout << "Min = " << min << endl; //Print min
            cout << "Max = " << max << endl; //Print max
        }  
}