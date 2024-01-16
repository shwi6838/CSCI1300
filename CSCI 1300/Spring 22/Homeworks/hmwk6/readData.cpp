// CSCI 1300 Spring 2022
// Author: Shane Wierl
// Recitation: 105 – Tiffany Phan
// Homework 6 - Problem #3

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int readData(string file, string drivers[], int attributes[][3], int arrSize, int splits)
{
    ifstream fin; // create an input file stream object
    
    fin.open(file); // open file.txt with the file stream object

    string line = "";
    int row = 0;
    if(fin.fail())
    {
        cout << "Could not open file." << endl; 
        return -1;
    }
    getline(fin, line);
    string arr[4] = {};
    if(split(line, ',', arr, 4)==splits);
    {
        drivers[row] = arr[0];
        attributes[0][0] = stoi(arr[1]);
        attributes[0][1] = stoi(arr[2]);
        attributes[0][2] = stoi(arr[3]);
        row++;
    }

    while (!fin.eof())
    {
        getline(fin, line); // read each line from the file
        if(split(line, ',', arr, 4)==splits);
        {
            drivers[row] = arr[0];
            attributes[row][0] = stoi(arr[1]);
            attributes[row][1] = stoi(arr[2]);
            attributes[row][2] = stoi(arr[3]);
            row++;
            if(row == arrSize)
                return row;
        }
    }

    return row;
}