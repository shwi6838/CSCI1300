//CSCI 1300 Spring 2022
//Author: Shane Wierl
//Recitation 105 – Tiffany Phan
//Project 1 - Problem 4

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

int main()
{
    //double x = tuneSimilarity("Hello", "G8F1C2");
    //cout << x << endl;

    assert(tuneSimilarity("A5F4D3", "A3F5D3") == 2.0); //Test 1

    assert(tuneSimilarity("A4F5D3", "G8F1C2") == -1.6667); //Test 2

    assert(tuneSimilarity("") == 0); //Test 3

    return 0;
}