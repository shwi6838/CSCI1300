#pragma once
#include<iostream>
#include<vector>
#include"Card.h"
#include"User.h"

using namespace std;

class Game
{
    private:
    int battleCount;
    vector <Card> overallDeck;
    int totalCards;

    public:
    Game();

    //Getters
    vector<Card> readCards(string);
    vector<Card> getOverallDeck();
    int getBattleCount();
    int getTotalCards();


    //Setters
    void RecordNewCard(string, Card);
    void upgradeHealth(Card);
    void upgradeDamage(Card);
    Card findCard(int);
    Card mergeCards(Card, Card, string);
    void sacrificeCard(Card, User);
    void setBattleCount(int);
};

