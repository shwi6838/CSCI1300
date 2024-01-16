// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 5 - Problem #2

/*
Algorithm: Create functions to calculate the max value in an array, the sum of all values in an array, and the average value of an array

*/

#include<iostream> //input/output stream

using namespace std;

double max(double arr[], int size) //Finds max value in array
{
    double max = 0; //Create a low max to compare to
    for(int i = 0; i < size; i++) //Loop through array
    {
        if(arr[i] >= max) //Compares the index of array to the max
            max = arr[i]; //Sets the max equal if the array value is greater
    }
    return max; //returns the greatest value 
}

double sum(double arr[], int size) //Calculates sum of all values
{
    double sum = 0; //Starting sum value
    for(int i = 0; i < size; i++) //Loops through array
    {
        sum += arr[i]; //Adds value at index to the sum
    }
    return sum; //Returns the total sum
}

double average(double arr[], int size) //Calculates the average of all values in an array
{
    double sum = 0; //Sum value
    double avg; 
    for(int i = 0; i < size; i++) //loops through array
    {
        sum += arr[i]; //Adds value at index to sum
    }
    avg = sum / size; //Average = sum / size(number of values)
    return avg; //Returns the average 
}

int main()
{
    
}