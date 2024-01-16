#pragma once
#include<iostream>
#include<vector>
#include"Card.h"
#include"User.h"

using namespace std;

class Table
{
    private:
        string tname;
        static const int Trows =2;
        static const int Tcols =4;
        Card TableData[Trows][Tcols];
        int Userpoints;
        int Enemypoints;

    public:
        Table();
        void displayTable();

        //Getters
        string getName();
        Card getCardAt(int,int);
        
        int getCardRow(Card);
        int getCardCol(Card);
        int getEnpoints();
        int getUserpoints();

        //Setters
        void setName(string);
        bool placeCard(Card, int, int);
        void killCards();

        void setEnpoints(int);
        void setUserpoints(int);

        void battleCards();

};
