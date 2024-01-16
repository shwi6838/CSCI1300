//CSCI 1300 Spring 2022
//Author: Shane Wierl
//Recitation 105 – Tiffany Phan
// Project 1 - Problem 1

#include<iostream>
#include<cassert>
#include<string>

using namespace std;

/*
Algorithm: Checks if input is a valid note in SPN
Accepts a string input, Outputs a bool
Check to see if note is the right length of 2
Checks the first character to be between A and G, checks the second character to be between 0 and 9
*/
bool isValidNote(string note)
{
    int length = note.length();

    if(length == 2) //Checks for a note length (has to be 2)
    {
        for(int i = 0; i <= length; i++) //Loops through note
        {
            if((note[i] >= 'A') && (note[i] <= 'G') && (note[i+1] >= '0') && (note[i+1] <= '9')) //The first index must be a letter between A and G, The second index must be a number between 0 and 9
            {
                return true; //The letter and number are within bounds
            }
            else
            {
                return false; //The letter or number does not match the bounds/parameters
            }
        }
    }
    else
    {
        return false;
    }
return false;
}

int main()
{
    assert(isValidNote("B5") == true); //Test 1; expect true

    assert(isValidNote("Hello") == false); //Test 2; expect false

    assert(isValidNote("J7") == false); //Test 3; expect false

    assert(isValidNote("C11") == false); //Test 4; expect false

    assert(isValidNote("E8") == true); //Test 5; expect true

    return 0;
}

