//CSCI 1300 Spring 2022
//Author: Shane Wierl
//Recitation 105 – Tiffany Phan
//Project 1 - Problem 6

#include<iostream>
#include<cassert>
#include<string>
//#include"bestSimilarity.cpp"
//#include"tuneSimilarity.cpp"

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

/*
Algorithm: Checks if input is a valid tune in SPN
Accepts 3 tune inputs and a target tune, Outputs a string statement
Calculates the best similarities of each input to the target
Compares the values to eachother
If all are zero or greater, they are all good, if all under zero, all are the worst
Checks if some are equal to eachother or tied
Checks which are greater or less
*/

void printWorstTune(string tune1, string tune2, string tune3, string target)
{
    double sim1 = bestSimilarity(tune1, target); //Calculates each best similarty value
    double sim2 = bestSimilarity(tune2, target);
    double sim3 = bestSimilarity(tune3, target);

    if((sim1 >=0) && (sim2 >=0) && (sim3 >=0)) //Checks if all are greater than zero
        cout << "No tune is the worst." << endl;
    else if((sim1 < 0) && (sim2 < 0) && (sim3 < 0)) //Checks if all are less than zero
        cout << "All tunes are the worst!" << endl;
    else if((sim1 == sim2) && (sim1 < sim3) && (sim1 < 0)) //Checks if 1 and 2 are same, and both less than zero
        cout << "Tunes 1 and 2 are tied for the worst!" << endl;
    else if ((sim1 == sim3) && (sim1 < sim2) && (sim1 < 0)) //Checks if 1 and 3 are same and less than zero
        cout << "Tunes 1 and 3 are tied for the worst!" << endl;
    else if((sim2 == sim3) && (sim2 < sim1) && (sim2 < 0)) //Checks if 2 and 3 are same and less than zero
        cout << "Tunes 2 and 3 are tied for the worst!" << endl;
    else if((sim1 < sim2) && (sim1 < sim3) && (sim1 < 0)) //Checks if only 1 is less than zero, and the other tunes
        cout << "Tune 1 is the worst!" << endl;
    else if((sim2 < sim1) && (sim2 < sim3) && (sim2 < 0)) //Checks if only 2 is less than zero, and the other tunes
        cout << "Tune 2 is the worst!" << endl;
    else if((sim3 < sim2) && (sim3 < sim1) && (sim3 < 0)) //Checks if only 3 is less than zero, and the other tunes
        cout << "Tune 3 is the worst!" << endl;
}

int main()
{
    printWorstTune("A2B5", "F4D5G4", "D4D7", "A8F3D6E7"); //Test 1; expect "No tune is the worst."

    printWorstTune("A2B5", "F5F6F7F2", "F5F5F5F5F5", "A2D5G8D7"); //Test 2; expect "Tune 2 is the worst!"

    return 0;
}