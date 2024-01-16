// CSCI 1300 Spring 2022</br>
// Author: Shane Wierl</br>
// Recitation: 105 – Tiffany Phan</br>
// Homework 5 - Problem #3b

/*
Algorithm: Insert the uppercase form of every consonant after every consonant in a string
Check for the size restaints 
Ignore the vowels
At every consonant, insert an uppercase letter after 

*/
#include<iostream>
#include<string>

using namespace std;

int insertConsonants(char inputCharacters[], int numElements, int size, int numConsonants)
{
    if(size < numElements + numConsonants) //Checks for if the number of elements and additional consonants are within the array size
    {
        return numElements; //Returns only the number of elements if the size is too small
    }

    for(int i = 0; i <= size; i++) //Loops through the character array
    {
        if(inputCharacters[i] == 'a' || inputCharacters[i] == 'e' || inputCharacters[i] == 'i' ||inputCharacters[i] == 'o' || inputCharacters[i] == 'u')
        {
            //Nothing because it is a vowel
        }
        else //Consonants
        {
            insertAfter(inputCharacters,numElements,size,i,(char)(inputCharacters[i]-32)); //Inserts an uppercase consonant after
            numElements+=1; //Increases/updates the number of elements
            i++; //Increase index to ignore the consonant inserted after
        }
    }
    return numElements-1; //Returns the number of total elements
}