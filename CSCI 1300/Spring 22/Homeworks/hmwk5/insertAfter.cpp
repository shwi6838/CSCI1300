// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 5 - Problem #3a

/*
Algorithm: Insert a character after a certain index, return a bool if it is possible within array
Check for bounds
Shift every array value and add the new character into the empty spot
*/
#include<iostream>
#include<string>

using namespace std;

bool insertAfter(char inputCharacters[], int numElements, int size, int index, char charToInsert)
{
    if(index >= size) //Checks for if index is out of bounds
        return false;
    if(size < numElements+1) //Checks for if the number of elements with the added element is within the size
        return false;
    if(index < 0) //Index cannot be negative
        return false;
    
    for(int i = size; i > index; i--) //Loops through the array backwards
    {
       inputCharacters[i] = inputCharacters[i-1]; //Shifts every index value to the right
    }
    inputCharacters[index+1] = charToInsert; //Adds the character into the new empty space
    return true;
}
