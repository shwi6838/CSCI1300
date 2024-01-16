//CSCI 1300 Spring 2022
//Author: Shane Wierl
//Recitation 105 – Tiffany Phan
//Project 1 - Problem 5

#include<iostream>
#include<cassert>
#include<string>
using namespace std;

/*
Algorithm: Checks if two tunes are similar
Accepts 2 string inputs of notes, Outputs a double value
Check to see if the lengths are the same
Finds total notes using length
Iterates through tunes and compares values of notes created using substrings
If the letter note is the same, adds to a matching notes counter
If the pitch is the same also, adds to a matching notes and pitch counter
If the letter is different but number(pitch) is the same, adds to a different note same pitch counter
Calculates similarity using formula and returns it
*/

double tuneSimilarity(string tune1, string tune2)
{
    double length1 = tune1.length();
    double length2 = tune2.length();
    double totalNotes = tune1.length()/2; //Length of tune in notes
    double matchNotes = 0; //Matching notes (letters)
    double matchNotesPitch = 0; //Matching notes (letters) and pitch (numbers)
    double diffNotesPitch = 0; //Different notes (letters) but same pitch (numbers)

    if(length1 != length2) //Checks for the same length tune, if they are not equal, there is no similarity
        return 0;
    
    for(int i = 0; i < length1; i+=2)
    {
        string note1 = tune1.substr(i,2); //Creates substrings (Notes of length 2) 
        string note2 = tune2.substr(i,2);

        if(note1[0] == note2[0]) //Checks for matching note (letter)
        {
            matchNotes ++;
            if(note1[1] == note2[1]) //Check for matching pitch (number)
                matchNotesPitch ++;
        }
        else
        {
            if(note1[1] != note2[1]) //Check for matching pitch (number), Note (letter) is different
                diffNotesPitch ++;
        }
    }
    double similarity = ((matchNotes/totalNotes) + matchNotesPitch - diffNotesPitch); //Calculates the similarity using formula
    return similarity;
}

/*
Algorithm: Checks tune similarites of tunes of different lengths and returns the best value
Accepts 2 string note inputs, Outputs a double value
Check to see if input tune is smaller than target tune, returns a 0 similarity if so
Iterates through the input tune and compares substrings of the target tune length to the target tune using tuneSimilarity
Updates the bestValue to be the highest value while looping through the input tune
Returns the best value
*/

double bestSimilarity(string input, string target)
{
    double bestSimilarity = -1000; //Creates a very low number to compare to that everything will be greater than initially
    double compareSimilarity = 0;
    double inputlen = input.length();
    double targetlen = target.length();

    if(inputlen < targetlen) // Checks is input tune is less than target tune in length
    {
        bestSimilarity = 0;
        return bestSimilarity; //Best similarity = 0
    }
    else
    {
        for(int i =0; i < inputlen-targetlen+1; i+=2)
        {
            compareSimilarity = tuneSimilarity(input.substr(i,targetlen), target); //Loops through input and compares it's substrings to the target
            if(compareSimilarity >= bestSimilarity) 
                bestSimilarity = compareSimilarity; // Replaces the value with the higher one
        }
    }
    return bestSimilarity;
}

int main()
{
    //double x = bestSimilarity("A3D4F9B3C8E1F2", "G3A4");
    //cout << x << endl;

    assert(bestSimilarity("F4D4E4", "G8F4C2D5E9C4A3") == 0); //Test 1

    assert(bestSimilarity("A4F5D3D4B7", "D3D4") == 3); //Test 2

    return 0;
}