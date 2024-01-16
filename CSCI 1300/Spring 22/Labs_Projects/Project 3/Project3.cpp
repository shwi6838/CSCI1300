#include<fstream>
#include<string>
#include<iomanip>
#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

#include"Card.h"
#include"User.h"
#include"Table.h"
#include"Enemy.h"
#include"Map.h"
#include"Game.h"

using namespace std;

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

void Menu(vector<Card> userDeck, vector<Card> playDeck, User you, Map map, bool game)
{
    //Menu
    bool Menu = true;
    while(Menu == true)
    {
        cout << "------Menu------" << endl;
        cout << "1. Move Forward (Exit Menu)" << endl;
        cout << "2. View User Deck" << endl;
        cout << "3. View Map" << endl;
        cout << "4. View Map Key" << endl;
        cout << "5. Give up and Die. (You will have to start over and forfeit progress)" << endl;

        int input;
        cin >> input;

        if(input == 1)
        {
            cout << "Lets see where you can go.." << endl;
            Menu = false;
        }
        else if (input == 2)
        {
            you.displayDeck(userDeck);
        }
        else if(input == 3)
        {
            map.displayMap();
        }
        else if(input == 4)
        {
            cout << "Letters on the map are Nodes." << endl;
            cout << "X is the Player" << endl;
            cout << "B are Battles. You must win to move past" << endl;
            cout << "N is a New Card Creator" << endl;
            cout << "F is Find a Card" << endl;
            cout << "S is Sacrifice a Card" << endl;
            cout << "D and H are upgrade spots for Damage and Health" << endl;
            cout << "M is Merging Cards" << endl;
        }
        else if(input == 5)
        {
            cout << "The woods are too much to bear. You give up. You curl up in a ball until the forest takes you..." << endl;
            cout << "Goodbye " << you.getName() << ". May we meet again." << endl;
            you.resetDeck(userDeck);
            you.resetDeck(playDeck);
            Game();
            Menu = false;
            game = false;
        } 
        else
        {
            cout << "Invalid Input" << endl;
        }  
    }
}

void LandSpot(char c, Game g, User you, bool game, vector <Card> userDeck, vector <Card> playDeck, Card TableData[2][4])
{
    if(c == 'N')
    {
        cout << "You have found ancient texts teaching how to create a new Card.." << endl;
        cout << "Write the name you wish the card to posess: " << endl;
        string Newname;
        cin >> Newname;
        cout << "Now, How much damage will it have? (Min is 1; Max is 4)" << endl;
        int Newdam;
        cin >> Newdam;
        cout << "Now, how much health will it have? (Min is 1; Max is 4)" << endl;
        int Newhealth;
        cin >> Newhealth;
        int level;
        if((Newdam <=2) && (Newhealth <=2))
            level = 1;
        else if((Newdam ==3 ) || (Newhealth == 3))
            level = 2;
        else
            level = 3;
        Card newC(Newname, Newdam, Newhealth, level);
        g.RecordNewCard("CardData.txt", newC);
        newC.displayCard();
        you.addCard(newC, userDeck);
    }
    else if(c == 'F')
    {
        cout << "You stumbled across a Cardsmen who offers you some cards..." << endl;
        int level = g.getBattleCount();
        if(level == 0)
            level = 1;
        if(level > 3)
            level = 3;
        Card a_ = g.findCard(level);
        Card b_ = g.findCard(level);
        Card c_ = g.findCard(level);

        cout << "Which card would you like? (1, 2, 3)" << endl;
        int hmm;
        cin >> hmm;
        if(hmm == 1)
        {
            cout << "Ah the " << a_.getName() << ". Good choice Traveler." << endl;
            you.addCard(a_, userDeck);
        }
        else if(hmm == 2)
        {
            cout << "Ah the " << b_.getName() << ". Good choice Traveler." << endl;
            you.addCard(b_, userDeck);
        }
        else if(hmm == 3)
        {
            cout << "Ah the " << c_.getName() << ". Good choice Traveler." << endl;
            you.addCard(c_, userDeck);
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    else if(c == 'H')
    {
        cout << "You have discovered a magic Trader.." << endl;
        cout << "Give him a card and he will upgrade it's health" << endl;

        you.displayDeck(userDeck);
        cout << "Pick a card. (Enter a number from 0 to " << you.getNumCards() << ")" << endl;
        int mhm;
        cin >> mhm;
        if((mhm >0 ) && (mhm <= you.getNumCards()))
        {
            g.upgradeHealth(userDeck[mhm-1]);
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    else if(c == 'D')
    {
        cout << "You have discovered a magic Trader.." << endl;
        cout << "Give him a card and he will upgrade it's damage" << endl;

        you.displayDeck(userDeck);
        cout << "Pick a card. (Enter a number from 0 to " << you.getNumCards() << ")" << endl;
        int mhm;
        cin >> mhm;
        if((mhm >0 ) && (mhm <= you.getNumCards()))
        {
            g.upgradeDamage(userDeck[mhm-1]);
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    else if(c == 'M')
    {
        cout << "You have disovered an ancient card merging wizard.." << endl;
        cout << "Choose two cards to merge into one better one" << endl;

        you.displayDeck(userDeck);
        cout << "Pick your first card. (Enter a number between 0 and " << you.getNumCards() << ")" << endl;
        int d;
        cin >> d;
        if((d >0 ) && (d <= you.getNumCards()))
        {
            you.displayDeck(userDeck);
            cout << "Pick your second card. (Enter a number between 0 and " << you.getNumCards() << ")" << endl;
            int e;
            cin >> e;
            if((d >0 ) && (d <= you.getNumCards()))
            {
                cout << "Which name would you like to keep?" << endl;
                cout << userDeck[d].getName() << " or " << userDeck[e].getName() << "? (Pick 1 or 2)" << endl;
                int cardname;
                cin >> cardname;
                string name;
                if(cardname == 1)
                {
                    name = userDeck[d].getName();
                }
                else if (cardname == 2)
                {
                    name = userDeck[e].getName();
                }
                Card f = g.mergeCards(userDeck[d], userDeck[e], name);
                f.displayCard();
                you.addCard(f, userDeck);
                you.removeCard(userDeck[d], userDeck);
                you.removeCard(userDeck[e], userDeck);
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    else if(c == 'S')
    {
        cout << "You have discovered a magic Trader.." << endl;
        cout << "Give him a card to sacrifice and he will reward you with a better card.." << endl;

        you.displayDeck(userDeck);
        cout << "Pick a card. (Enter a number from 0 to " << you.getNumCards() << ")" << endl;
        cout << "Card can only be a level 1 or 2 to Sacrifice." << endl;
        int mhm;
        cin >> mhm;
        if((mhm >0 ) && (mhm <= you.getNumCards()))
        {
            if(userDeck[mhm].getLevel() == 3)
            {
                cout << "Card level must be 1 or 2" << endl;
            }
            else
            {
                g.sacrificeCard(userDeck[mhm], you);
            }
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    else if(c == 'B')
    {
        g.setBattleCount(g.getBattleCount()+1);
        int Elevel = g.getBattleCount();
        if(Elevel == 0)
            Elevel = 1;
        if(Elevel > 3)
            Elevel = 3;
        Enemy m("Enemy", Elevel);
        m.fillDeck(Elevel, g);
        cout << "You have been captured by the enemy and are forced to play a game of Cards with him.." << endl;
        Table Battle_;

        Card j = m.getRandomCard();
        Battle_.placeCard(j,0,rand()%4);
        Battle_.displayTable();

        you.pickCardFromDeck();
        you.pickCardFromDeck();
        you.pickCardFromDeck();

        cout << "Place your first card: (1,2,3)" << endl;
        you.displayDeck(playDeck);
        int card;
        cin >> card;
        Card p;
        if(card == 1)
        {
            p = playDeck[0];
        }
        else if(card ==2)
        {
            p = playDeck[1];
        }
        else if(card ==3)
        {
            p = playDeck[2];
        }
        else
        {
            cout << "Invalid Input" << endl;
        }

        cout << "Choose a spot: (1-4)" << endl;
        Battle_.displayTable();
        int index;
        cin >> index;
        if((index == 1) || (index == 2) || (index == 3) || (index ==4))
        {
            Battle_.placeCard(p, 1, index-1);
        }
        Battle_.displayTable();

        while(((Battle_.getEnpoints() - Battle_.getUserpoints()) <= 5) || ((Battle_.getUserpoints() - Battle_.getEnpoints()) <= 5))
        {
            Battle_.battleCards();
            Battle_.killCards();

            //Enemy turn here


            bool UserTurn = true;
            while(UserTurn = true)
            {
                Battle_.displayTable();
                cout << "Pick a card: " << endl;
                you.pickCardFromDeck();
                you.displayDeck(playDeck);

                cout << "Pick a card, Place a Card, or End Turn? (1,2,3)" << endl;
                int action;
                cin >> action;
                if(you.getNumCards() == 0);
                {
                    action = 2;
                    if(you.getNumPlayCards() == 0)
                    {
                        action = 3;
                    }
                }
                if(action == 1)
                {
                    you.pickCardFromDeck();
                    you.displayDeck(playDeck);
                }
                else if(action ==2)
                {
                    cout << "Place your card: (1 to " << you.getNumPlayCards() << ")" << endl;
                    you.displayDeck(playDeck);
                    int dard;
                    cin >> dard;
                    Card q;
                    if((dard >= 1) && (dard <= you.getNumPlayCards()))
                    {
                        q = playDeck[dard];
                    }
                    else
                    {
                        cout << "Invalid Input" << endl;
                    }

                    cout << "Choose a spot: (1-4)" << endl;
                    Battle_.displayTable();
                    int index;
                    cin >> index;
                    if((index == 1) || (index == 2) || (index == 3) || (index ==4))
                    {
                        Battle_.placeCard(q, 1, index-1);
                    }
                    Battle_.displayTable();
                }
                else if(action ==3)
                {
                    UserTurn = false;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
        }
        if(Battle_.getEnpoints() > Battle_.getUserpoints()+5)
        {
            cout << "The enemy has won... He takes your life..." << endl;
            m.resetDeck();
            you.resetDeck(userDeck);
            you.resetDeck(playDeck);
            Game();
            game = false;
        }
        else if(Battle_.getUserpoints() > Battle_.getEnpoints()+5)
        {
            cout << "You have won! You can move on.." << endl;
            m.resetDeck();
            you.resetDeck(playDeck);
            if(g.getBattleCount() == 4)
            {
                cout << "You have Won the game! You may leave the scary forest and live on.." << endl;
                cout << "Congradulations, " << you.getName() << "!" << endl;
                Game();
                you.resetDeck(userDeck);
                you.resetDeck(playDeck);
                game = false;
            }
        }
    }
}

int main()
{
    srand(time(0));
    bool game = true;
    while(game == true)
    {
        vector <Card> userDeck;
        vector <Card> overallDeck;
        vector <Card> playDeck;
        vector <Card> enemyDeck;
        char MapData[39][15];
        Card TableData[2][4];

        Map map;
        Game g;

        //Introduction to Game
        string usern;
        cout << "Welcome to Card Wanderer: An Inscryption Inspired Game" << endl;
        cout << "Please enter username:" << endl;
        cin >> usern;
        User you(usern);
        
        cout << "Hello, " << you.getName() << endl;
        cout << "You seem to be lost in the woods. Luckily I have found a path for you.." << endl;
        cout << endl;
        map.readMapData("MapData.txt");
        map.fillRandomEvent();
        map.displayMap();

        cout << "These woods are full of dangerous wanderers, who deal with the ways of Cards.." << endl;
        cout << "To pass them you must beat them in battles. Pass the final battle and you are free." << endl;
        cout << "Oh. You dont have any Cards? You will find them on the path. There are many traders and Cardsmen." << endl;
        cout << "I will give you a few to start." << endl;

        overallDeck = g.readCards("CardData.txt");
        Card a = g.findCard(1);
        Card b = g.findCard(1);
        Card c = g.findCard(1);
        cout << "This is only a start. Find a way to use them in battle. Good Luck Traveler " << you.getName() << endl;
        you.addCard(a, userDeck);
        you.addCard(b, userDeck);
        you.addCard(c,userDeck);

        Menu(userDeck, playDeck, you, map, game);

        while(game == true)
        {
            cout << "Lets see what paths we can take.." << endl;
            int b = map.Branches();
            int row = map.getUserRow();
            int col = map.getUserCol();
            char event = map.getCharNode(row,col);
            if(b == 1)
            {
                map.displayMap();
                cout << "You may only move forward" << endl;
                if(MapData[row-1][col-1] == '\\')
                {
                    map.setUserPos(row-2, col-2);
                }
                if(MapData[row-1][col] == '|')
                {
                    map.setUserPos(row-2,col);
                }
                if(MapData[row-1][col+1] == '/')
                {
                    map.setUserPos(row-2,col+2);
                }
            }
            if(b == 2)
            {
                map.displayMap();
                cout << "You can move 2 ways. Choose Left(1) or Right(2)" << endl;
                int path;
                cin >> path;
                if(path == 1)
                {
                    if(MapData[row-1][col-1] == '\\')
                    {
                        map.setUserPos(row-2, col-2);
                    }
                    if(MapData[row-1][col] == '|')
                    {
                        map.setUserPos(row-2,col);
                    }
                }
                else if(path == 2)
                {
                    if(MapData[row-1][col] == '|')
                    {
                        map.setUserPos(row-2,col);
                    }
                    if(MapData[row-1][col+1] == '/')
                    {
                        map.setUserPos(row-2,col+2);
                    }
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }
            if(b == 3)
            {
                map.displayMap();
                cout << "You can move 3 ways. Choose Left(1) or Right(2) or Forward(3)" << endl;
                int path;
                cin >> path;
                if(path == 1)
                {
                    map.setUserPos(row-2, col-2);
                }
                else if(path == 2)
                {
                    map.setUserPos(row-2,col+2);
                }
                else if(path == 3)
                {
                    map.setUserPos(row-2,col);
                }
                else
                {
                    cout << "Invalid Input" << endl;
                }
            }

            LandSpot(event, g, you, game, userDeck,playDeck, TableData);
            
            Menu(userDeck, playDeck, you, map, game);
        }
    }
}