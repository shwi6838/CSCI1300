// CSCI 1300 Spring 2022
// Author: Shane Wierl
// Recitation: 105 – Tiffany Phan
// Homework 6 - Problem #2

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int readDrivers(string file)
{
    ifstream fin; // create an input file stream object
    
    fin.open(file); // open file1.txt with the file stream object

    if (fin.is_open())
    {
        int drivers;
        string line = "";
        string arr[100];

        while (!fin.eof())
        {
            getline(fin, line); // read each line from the file 
            if(split(line, ',', arr, 3) == 3)
            {
                drivers++;
            }
            else
            {
                //Nothing
            }
        }
        return drivers;
    }
    else 
    {
        cout << "Could not open file." << endl; 
        return -1;
    }
    // closing the file
    fin.close();
}