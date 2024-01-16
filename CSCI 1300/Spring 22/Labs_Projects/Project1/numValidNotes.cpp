//CSCI 1300 Spring 2022
//Author: Shane Wierl
//Recitation 105 – Tiffany Phan
//Project 1 - Problem 3

#include<iostream>
#include<cassert>
#include<string>
//#include"isValidNote.cpp"

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
Algorithm: Check for valid notes and count them

*/

int numValidNotes(string input)
{
    int length = input.length();
    int count = 0;

    for(int i = 0; i <= length; i++)
    {
        if(isValidNote(input.substr(i,2)) == true)
            count ++;
    }
    return count;
}

int main()
{
    assert(numValidNotes("B5HT2") == 1); //Test 1; expect 1 valid note

    assert(numValidNotes("A3N7F4V6C1") == 3); //Test 2; expect 3 valid notes

    assert(numValidNotes("HY56V7M654") == 0); //Test 3; expect no valid notes

    assert(numValidNotes("Hello Everyone") == 0); //Test 4; expect no valid notes

    assert(numValidNotes("E8G5D4C6X2") == 4); //Test 5; expect 4 valid notes

    return 0;
}