//CSCI 1300 Spring 2022
//Author: Shane Wierl
//Recitation 105 – Tiffany Phan
//Project 1 - Problem 7

#include<iostream>
#include<cassert>
#include<string>
#include<iomanip>

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
        string note1 = tune1.substr(i,2); //Creates substrings (Notes) 
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
        return bestSimilarity; //Best similarity is 0
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

/*
Algorithm: Create a menu to use and compare tunes
Inputs a choice, and uses a switch statement to go to each choice and use each function
Each function will ask for its inputs, and check if they are valid
Will keep asking until the input is valid SPN
Will calculate similarity using functions
*/

int main()
{
    cout << (fixed) << setprecision(2);
    char choice;
    bool go = true;
    while(go == true) //Keeps giving menu until user wants to exit
    {
        cout << "--- Menu ---" << endl;
        cout << "1. Calculate similarity between two tunes." << endl;
        cout << "2. Calculate best similarity between two tunes of potentially different lengths." << endl;
        cout << "3. Find the least similar tune out of three input tunes and one target." << endl;
        cout << "4. Exit." << endl;
        cout << "Please enter your choice (1 - 4):" << endl;
        cin >> choice;

        switch (choice)
        {
            case '1': //Inputs 2 tunes and calculates their similarity
            {
                string tune1;
                string tune2; 
                
                cout << "Please enter the first tune:" << endl;
                cin >> tune1;
                bool valid1 = isValidTune(tune1);
                while(valid1 == 0) //Checks the validity of tune 1
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune1;
                    valid1 = isValidTune(tune1);
                }

                cout << "Please enter the second tune:" << endl;
                cin >> tune2;
                bool valid2 = isValidTune(tune2);
                while(valid2 == 0) // Checks validity
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune2;
                    valid2 = isValidTune(tune2);
                }

                double similarity = tuneSimilarity(tune1,tune2);
                cout << "The similarity score is " << similarity << endl; //Calculates and returns their similarity
                break;
            }
            case '2': // Inputs a tune and a target and finds the best similarity
            {
                string input;
                string target;

                cout << "Please enter the input tune:" << endl;
                cin >> input;
                bool valid1 = isValidTune(input);
                while(valid1 == 0) // Checks validity
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> input;
                    valid1 = isValidTune(input);
                }

                cout << "Please enter the target tune:" << endl;
                cin >> target;
                bool valid2 = isValidTune(target);
                while(valid2 == 0) //Checks validity
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> target;
                    valid2 = isValidTune(target);
                }
                
                double Bsimilarity = bestSimilarity(input,target);
                cout << "The best similarity score is: " << Bsimilarity << endl; //Calculates and returns the best similarity value
                break;
            }
            case '3': // Inputs 3 tunes and a target and compares each tune
            {
                string tune1;
                string tune2;
                string tune3;
                string target;

                cout << "Please enter the first tune:" << endl;
                cin >> tune1;
                bool valid1 = isValidTune(tune1);
                while(valid1 == 0) //Checks validity
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune1;
                    valid1 = isValidTune(tune1);
                }
                
                cout << "Please enter the second tune:" << endl;
                cin >> tune2;
                bool valid2 = isValidTune(tune2);
                while(valid2 == 0) //Checks validity
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune2;
                    valid2 = isValidTune(tune2);
                }
                
                cout << "Please enter the third tune:" << endl;
                cin >> tune3;
                bool valid3 = isValidTune(tune3);
                while(valid3 == 0) //Checks validity
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune3;
                    valid3 = isValidTune(tune3);
                }
                
                cout << "Please enter the target tune:" << endl;
                cin >> target;
                bool valid4 = isValidTune(target);
                while(valid4 == 0) //Checks validity
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> target;
                    valid4 = isValidTune(target);
                }

                printWorstTune(tune1,tune2,tune3,target);  //Compares tunes and prints a statement
                break;
            }
            case '4': //Says goodbye and ends the while loop to end the code
            {
                cout << "Goodbye!" << endl;
                go = false;
                break;
            }
            default: //Checks for invalid inputs
            {
                cout << "Invalid Input." << endl;
                break;
            }
        }
    }
}