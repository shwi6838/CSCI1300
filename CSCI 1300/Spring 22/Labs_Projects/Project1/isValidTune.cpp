//CSCI 1300 Spring 2022
//Author: Shane Wierl
//Recitation 105 – Tiffany Phan
//Project 1 - Problem 2

#include<iostream>
#include<cassert>
#include<string>
//#include"isValidNote"

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

/*
Algorithm: Checks if input is a valid tune in SPN
Accepts a string input, Outputs a bool
Check to see if note is empty
Checks every two characters by iterating through the tune and tests each "note" using isValidNote
*/

bool isValidTune(string tune)
{
    int length = tune.length();

    if(length == 0) //Check for no length
        return false;
    
    for(int i = 0; i < length; i+=2) //Loop through string and create notes using substrings
    {
        if(isValidNote(tune.substr(i,2)) == false) //Checks for unvalid notes
            return false;
    }
    return true; //If no notes are false, then the tune is valid
}

int main()
{
    assert(isValidTune("B5F4A3B1") == true); //Test 1

    assert(isValidTune("A4F4N6") == false); //Test 2

    assert(isValidTune("Poundcake") == false); //Test 3

    assert(isValidTune("C16HG6") == false); //Test 4

    assert(isValidTune("E8F4D6A3C9") == true); //Test 5

    return 0;
}