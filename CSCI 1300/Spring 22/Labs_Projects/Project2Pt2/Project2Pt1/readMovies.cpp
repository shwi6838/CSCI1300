#include<iostream>
#include"Movie.h"
#include<fstream>
#include<string>

using namespace std:

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


int readMovies(string file, Movie movies[], int numMovie, int movieArrSize)
{
    ifstream fin; // create an input file stream object
    fin.open(file); // open file.txt with the file stream object

    if(numMovie >= movieArrSize)
        return -2;
    
    if(fin.fail())
        return -1;

    string line = "";
    string arr[2];
    int row = numMovies;
    while (!fin.eof())
    {
            getline(fin, line);
            if(split(line, ',', arr, 2))
            {
                Movie mov(arr[0], arr[1]);
                
                movies[row] = mov;
                row++;
                if(row == movieArrSize)
                    return row;
            }
    }
    return row;
}