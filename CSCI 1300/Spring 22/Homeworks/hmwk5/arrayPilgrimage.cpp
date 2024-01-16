// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 5 - Problem #1

/*
Create arrays and populate them with specific values
Print all arrays with each element on each line in order of distance, fruits, sequence, and letters
Distance - all values are 42.42
Fruit - print strings of fruit names
Sequence - print every multiple of 7 from 0 to 700
Letters print every letter with its lowercase form after it (A, a,B, b, ...)
*/

#include<iostream> //input/output stream

using namespace std;

int main() //main function
{
    float distance[10];
    string fruit[5] = {"Strawberry","Orange","Apple","Banana","Pineapple"};
    int sequence[100];
    char letters[52];   //Initialize every array

    for(int i =0;i < 10; i++) //Populate the Distance array with 42.42 values
    {
        distance[i] = 42.42;
        cout << distance[i] << endl; //Print every value in array
    }

    for(int i = 0; i < 5; i++) //Print the fruit array and its string values
    {
        cout << fruit[i] << endl;
    }

    for(int i = 0; i < 100; i++) //Populates the sequence array and prints its values
    {
        sequence[i] = (i+1)*7; //Every index is a multiple of 7
        cout << sequence[i] << endl;
    }

    char n = 65; //The decimal value of 'A'
    for(int i = 0; i < 52; i++) // loop through and populate the letters array
    {
        if(i%2 == 0) //At every even index add a capital letter
        {
            letters[i] = n; //Adds 'A'
            n = n + 32; //Changes the value to it's lowercase form for the next index of i
        }
        else
        {
            letters[i] = n; //Prints the lowercase form
            n = n - 31; //Changes back to its uppercase form for next index of i
        }
    }
    for(int i = 0; i < 52; i++)
        cout << letters[i] << endl; //Prints the letters in the array
}