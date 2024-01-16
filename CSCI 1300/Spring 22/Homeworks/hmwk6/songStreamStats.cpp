// CSCI 1300 Spring 2022
// Author: Shane Wierl
// Recitation: 105 – Tiffany Phan
// Homework 6 - Problem #1

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void songStreamStats(string filename)
{
    ifstream fin; // create an input file stream object
    
    fin.open(filename); // open file1.txt with the file stream object

    if (fin.is_open())
    {
        int mostStream = 0;
        int leastStream = 10000000;
        string line = "";
        string lsong = "";
        string msong = "";
        int lineidx = 0;
        string arr[2];
        while (!fin.eof())
        {
            getline(fin, line); // read each line from the file 
            split(line, ',', arr, 2);

            if(stoi(arr[1]) >= mostStream)
            {
                mostStream = stoi(arr[1]);
                msong = arr[0];
            }
            if(stoi(arr[1]) <= leastStream && stoi(arr[1]) < mostStream)
            {
                leastStream = stoi(arr[1]);
                lsong = arr[0];
            }
            if(line != "")
                lineidx ++;
        }
        cout << "Number of lines read: " << lineidx << "." << endl;
        cout << "Most streamed song: " << msong << " with " << mostStream << " streams." << endl;
        cout << "Least streamed song: " << lsong << " with " << leastStream << " streams." << endl;
    }
    else 
    {
        cout << "Could not open file." << endl;   
    }
    // closing the file
    fin.close();
}
