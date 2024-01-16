#pragma once
#include<iostream>
#include<vector>
#include "Card.h"
using namespace std;

class Game;

class Enemy
{
    private:
        string ename;
        vector <Card> EDeck;
        int EnumCards;
        int difficulty;
    
    public:
        Enemy();
        Enemy(string, int);

        //Getters
        string getName();
        int getNumCards();
        int getDifficulty();
        Card getRandomCard();
        vector<Card> getEDeck();

        //Setters
        void setName(string);
        void setDifficulty(int);
        void fillDeck(int, Game);
        void resetDeck();
};
