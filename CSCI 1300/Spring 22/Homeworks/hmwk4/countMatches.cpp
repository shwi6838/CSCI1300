// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 4 - Problem 4

/*
Initialize search and sub strings
Ask for search and sub strings
Iterate through search string and check every substring 
of the length of the sub to see if it is equal to the sub target string
At every instance, add to a counter
Print the count
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string search; 
    cout << "Enter the search string: " << endl;
    cin >> search;

    string sub;
    cout << "Enter the substring to be searched:" << endl;
    cin >> sub;

    int count = 0;
    for(int i =0; i < search.length();i++ )
    {
        if(search.substr(i,sub.length()) == sub)
            count++;
    }
    cout << "Number of occurrences: " << count << endl;
}