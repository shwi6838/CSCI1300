// CSCI 1300 Spring 2022
// Author: Shane Wierl
// Recitation: 105 – Tiffany Phan
// Homework 5 - Problem #4

/*
Algorithm: Split a string into an array of strings at a delimiter character
Save characters of string into a word
At each seperator, end the word and add it to an array
Start a new word and increase the array index
Count every word and return the number of pieces it was split into
*/
#include<iostream>
#include<string>

using namespace std;

int split(string inputString, char separator, string arr[],int size){
    
    arr[0]=inputString;
    int index=0; // index of the array
    int sepIndex=0; // index of the last separator found

    if(inputString=="") // check for empty input
    {
        return 0;
    }

    for(int i=0;i<inputString.length()+1;i++) // loop through input
    {
        if(inputString[i]==separator) //If separator is found
        {
            arr[index]=inputString.substr(sepIndex,i-sepIndex); //Add word created between separators at the index of the array
            sepIndex=i+1; // increase the separator index to start the next word 
            if(size==index+1) //check for bounds in size
            {
                return -1;
            }
            arr[index+1]=inputString.substr(sepIndex,i); //set up next index to start next word
            index++; //increase the index for array
        }
    }
    return index+1; //TReturns the number of splits + 1 to equal the number of words
}


