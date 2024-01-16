#include"User.h"
#include<vector>
#include "Card.h"

User::User()
{
    uname = "";
    numCards =0;
    numPlayCards = 0;
}

User::User(string name_)
{
    uname = name_;
    numCards = 0;
    numPlayCards = 0;
}

//Getters
string User::getName()
{
    return uname;
}

int User::getNumCards()
{
    return numCards;
}

int User::getNumPlayCards()
{
    return numPlayCards;
}

void BSortDeck(vector <Card> &deck)  //Bubble Sort a Deck by Level
{
    int i, j;
    int Length = deck.size();
    cout<<deck.size();
    for(j = 0; j <= Length; j++)
    {
        for(i = 0; i < Length-1; i++)
        {
            if(deck[i+1].getLevel() < deck[i].getLevel())
            {
                std::swap(deck[i+1] , deck[i]);
            }
        }
    }
    return;  
}

void User::displayDeck(vector <Card> deck) //Displays each card in a vector deck of cards in a list format by level
{
    BSortDeck(deck);
    for(int i = 0; i < deck.size(); i++)
    {
        deck[i].displayCard();
        cout << endl;
    }
}

vector<Card> User::getUserDeck() //Returns the userDeck
{
    vector<Card> copy;
    for(int i=0; i < numCards; i++)
    {
        copy.push_back(userDeck[i]);
    }
    return copy;
}

vector<Card> User::getPlayDeck() //Returns playDeck
{
    vector<Card> copy;
    for(int i=0; i < numPlayCards; i++)
    {
        copy.push_back(playDeck[i]);
    }
    return copy;
}

//Setters
void User::setName(string name) 
{
    uname = name;
}
void User::setNumCards(int n)
{
    numCards = n;
}

void User::setNumPlayCards(int n)
{
    numPlayCards = n;
}

void User::addCard(Card c, vector <Card> deck) //Add card to specified deck
{
    deck.push_back(c); 
    numCards++;
}

void User::removeCard(Card c, vector <Card> deck) //Removes target card from specified deck
{
    for(int i = 0; i < deck.size(); i++)
    {
        Card d = deck[i];
        if(d.getName() == c.getName())
        {
            deck.erase(deck.begin()+i-1); 
            numCards--;
        }
    }
}

void User::resetDeck(vector <Card> deck) //Clears deck of choice
{
    deck.clear(); 
    numCards = 0;
}

void User::pickCardFromDeck()  //User can pick card from their user deck that puts card into play deck
{
    Card c = userDeck[rand() % numCards];
    //Card should be random index of the user deck
    //When picked, card should be removed from user deck and added to play deck
    removeCard(c, userDeck);
    addCard(c, playDeck);
    int n = numCards-1;
    int d = numPlayCards+1;
    setNumCards(n);
    setNumPlayCards(d);
}


