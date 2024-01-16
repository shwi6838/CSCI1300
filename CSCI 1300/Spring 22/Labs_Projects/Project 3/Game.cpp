#include"Game.h"
#include"Table.h"
#include<fstream>
#include "User.h"

int split(string inputString, char separator, string arr[],int size)
{
    
    arr[0]=inputString;
    int index=0; // index of the array
    int sepIndex=0; // index of the last separator found

    if(inputString=="") // check for empty input
    {
        return 0;
    }

    for(int i=0;i<inputString.length()+1;i++) // loop through input
    {
        if(inputString[i]==separator) //If separator is found
        {
            arr[index]=inputString.substr(sepIndex,i-sepIndex); //Add word created between separators at the index of the array
            sepIndex=i+1; // increase the separator index to start the next word 
            if(size==index+1) //check for bounds in size
            {
                return -1;
            }
            arr[index+1]=inputString.substr(sepIndex,i); //set up next index to start next word
            index++; //increase the index for array
        }
    }
    return index+1; //Returns the number of splits + 1 to equal the number of words
}

Game::Game()
{
    battleCount = 0;
    overallDeck.empty();
}

//Getters
vector<Card> Game::readCards(string file) //Read a file and create Card objects for every line and add to an overall card vector
{
    ifstream fin; // create an input file stream object
    fin.open(file); // open file.txt with the file stream object
    
    if(fin.fail()) //Checks if file was not opened
        return overallDeck;
    
    string line = ""; 
    string arr[4];
    int i = totalCards; //Accounts for cards already in deck if needed
    while (!fin.eof())
    {
            getline(fin, line);
            if(split(line, ',', arr, 4)) //Splits each line
            {
                Card c(arr[0], int(arr[1].at(0)), int(arr[2].at(0)), int(arr[3].at(0))); //Creates card object using new array
                overallDeck[i] = c; //Adds Card to deck
                i++; //Adds to row index
                totalCards ++;
            }
    }
    return overallDeck;
}

vector<Card> Game::getOverallDeck()  //Returns overall game Deck
{
    vector<Card> copy;
    for(int i=0; i < totalCards; i++)
    {
        copy.push_back(overallDeck[i]);
    }
    return copy;
}

int Game::getBattleCount()
{
    return battleCount;
}

int Game::getTotalCards()
{
    return totalCards;
}

//Setters
void Game::RecordNewCard(string file, Card c)  //Write to cards file so can be used in other games and by enemy
{
    ofstream out;
    out.open(file);

    if(out.fail())
    {
        cout << "Could not write to file" << endl;
    }

    out << c.getName() << " , " << c.getDamage() << " , " << c.getHealth() << " , " << c.getLevel() << endl;

    out.close();
}

void Game::upgradeHealth(Card c) //Adds 1 to cards health
{
    c.setHealth(c.getHealth() + 1);
}

void Game::upgradeDamage(Card c) //Adds 1 to cards damage
{
    c.setDamage(c.getDamage()+1);
}

Card Game::findCard(int level)
{
    //Creates a vector of cards of that level from overall deck
    vector <Card> levelDeck;
    int numLevCards;
    for(int i  = 0; i < overallDeck.size(); i++)
    {
        if(overallDeck[i].getLevel() == level)
        {
            levelDeck.push_back(overallDeck[i]);
            numLevCards++;
        }
    }
    //Produce a random card from the deck of the same level
    Card c = levelDeck[rand() % numLevCards];
    c.displayCard();
    return c;
}

Card Game::mergeCards(Card c, Card d, string chosenName)
{
    //Add the damages and healths together
    int health = c.getHealth() + d.getHealth();
    int dam = c.getDamage() + d.getDamage();
    double levelAvg = (c.getLevel() + d.getLevel()) / 2;
    int newLevel;
    if(levelAvg == 1.0)
    {
        newLevel = 1;
    }
    else if(levelAvg <= 2.0)
    {
        newLevel = 2;
    }
    else if(levelAvg <= 3.0)
    {
        newLevel = 3;
    }
    //Create new card with these parameters, level increases by 1
    Card cd(chosenName, dam, health, newLevel);
    return cd;
}

void Game::sacrificeCard(Card c, User u)
{
    bool LoseCard = (rand() % 100) < 10;
    if(LoseCard == true)
    {
        cout << "They felt something was off about you... They flee and you get Nothing in return..." << endl;
        u.removeCard(c, u.getUserDeck());
    }
    else
    {
        Card d = findCard(c.getLevel()+1);
        d.displayCard();
        u.removeCard(c, u.getUserDeck());
        u.addCard(d, u.getUserDeck());
    }
    //Removes card from user deck and replaces with a random card from the next level up
    //Cannot sacrifice level 3 cards so check for level of card
}

void Game::setBattleCount(int b)
{
    battleCount = b;
}