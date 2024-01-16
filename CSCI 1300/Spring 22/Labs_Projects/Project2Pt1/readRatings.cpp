#include<iostream>
#include"User.h"
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

int readRatings(string file, User users[], int numUsers, int userArrSize, int maxRatings)
{
    ifstream fin; // create an input file stream object
    fin.open(file); // open file.txt with the file stream object

    if(numUsers >= userArrSize)
        return -2;

    if(fin.fail())
        return -1;

    string line = "";
    string arr[51];
    int row = numUsers;
    while (!fin.eof())
    {
        getline(fin, line);
        if(split(line, ',', arr, 51))
        {
            string user = arr[0];

            int rating[50];
            int numRating = 0;
            for(int i = 1; i < maxRatings+1; i++)
            {
                if(arr[i] != "")
                {
                    rating[i-1] = stoi(arr[i]);
                    numRating++;
                }
            }
            

            User u1 = User(user,rating,numRating);
            users[row] = u1;
            row++;

            if(row == userArrSize)
                return userArrSize;
        }
    }
    return row;
}
