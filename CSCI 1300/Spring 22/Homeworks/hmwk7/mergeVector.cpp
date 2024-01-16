// CSCI 1300 Spring 2022
// Author: Shane Wierl
// Recitation: 105 – Tiffany Phan
// Homework 7 - Problem #2

#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

/*
Algorithm: Merge all elements of a string vector into a string until a keyword is found.
Check for empty vector
Change each element to upper case forms in a holding string and compare to keyword "STOP"
Add every string element to a string with spaces between
Return string at keyword stop or when the vector has ended
*/

string mergeVector(vector<string> vec1)
{
    if(vec1.empty() == true) //Check for empty string
        return "0";

    string merged = ""; //String of elements
    for(int i = 0; i < vec1.size(); i++) //Change each term of vector to uppercase
    {
        string hold = vec1[i];
        for(int j = 0; j < hold.length(); j++)
        {
            hold[j] = toupper(hold[j]);
        }
        if(hold == "STOP") //Compare to keyword
            return merged; //Return string where it is at if keyword found
        else
            merged = merged + vec1[i] + " "; //Add elements to the string
            //cout << merged << endl;
    }
    return merged; //Return the final string
}

int main()
{	
    vector<string> vec1 = {"I", "love", "CSCI 1300"};
    cout << mergeVector(vec1) << endl;
    //Expected output: "I love CSCI 1300"

    vector<string> vec2 = {};
    cout << mergeVector(vec2) << endl;
    //Expected output: "0"

    vector<string> vec3 = {"Hello", "Howdy", "Hi", "StoP", "Hola", "BananA"};
    cout << mergeVector(vec3) << endl;
    //Expected output: "Hello Howdy Hi"
}