#include"Enemy.h"
#include"Game.h"
#include"Card.h"

Enemy::Enemy()
{
    ename = "";
    EnumCards = 0;
    difficulty = 0;
}

Enemy::Enemy(string name, int difficulty_)
{
    ename = name;
    EnumCards = 0;
    difficulty = difficulty_;
}

//Getters
string Enemy::getName()
{
    return ename;
}

int Enemy::getNumCards()
{
    return EnumCards;
}

int Enemy::getDifficulty()
{
    return difficulty;
}

Card Enemy::getRandomCard()  //Get random card from enemy's deck
{
    //Uses random int of the overall deck index
    //Enemy has access to all cards of a level
    int i = rand()%EnumCards;
    Card d = EDeck[i];
    return d;
}

vector<Card> Enemy::getEDeck() //Returns Enemy Deck
{
    vector<Card> copy;
    for(int i=0; i < EnumCards; i++)
    {
        copy.push_back(EDeck[i]);
    }
    return copy;
}

//Setters
void Enemy::setName(string name)
{
    ename = name;
}

void Enemy::setDifficulty(int difficulty_)
{
    difficulty = difficulty_;
}

void Enemy::fillDeck(int Elevel, Game g) //Fills enemy deck with cards of only that enemy's level
{
    for(int i = 0; i < g.getTotalCards(); i++)
    {
        if(g.getOverallDeck()[i].getLevel() == Elevel)
        {
            EDeck.push_back(g.getOverallDeck()[i]);
            EnumCards++;
        }
    }
    //Reads cards from full file deck and adds the cards with the target level to the enemy EDeck[] for them to use in battle
}

void Enemy::resetDeck()  //Clears deck of enemy
{
    EDeck.clear(); 
}