#pragma once
#include<iostream>
#include<vector>
#include "Card.h"

using namespace std;

class User
{
    private:
        string uname;
        vector <Card> userDeck;
        vector <Card> playDeck;
        int numCards;
        int numPlayCards;
        
    
    public:
        User();
        User(string);

        //Getters
        string getName();
        int getNumCards();
        int getNumPlayCards();
        void displayDeck(vector<Card>);
        vector<Card> getUserDeck();
        vector<Card> getPlayDeck();

        //Setters
        void setName(string);
        void setNumCards(int);
        void setNumPlayCards(int);
        void addCard(Card, vector <Card>);
        void removeCard(Card, vector <Card>);
        void resetDeck(vector <Card>);
        void pickCardFromDeck();

};
