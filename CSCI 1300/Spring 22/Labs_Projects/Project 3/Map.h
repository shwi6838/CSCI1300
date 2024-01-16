#pragma once
#include<iostream>
using namespace std;

class Map
{
    private:
    char eventChars[5] = {'H', 'D', 'M', 'S', 'F'};
    static const int Mrows = 39;
    static const int Mcols = 15;
    char MapData[Mrows][Mcols];

    public:
    bool readMapData(string);
    Map();

    void displayMap();

    //Getters
    int getUserRow();
    int getUserCol();
    int Branches();
    char getCharNode(int, int);
    
    //Setters
    bool setEvent(int, int, char);
    void fillRandomEvent();
    bool setUserPos(int, int);
};