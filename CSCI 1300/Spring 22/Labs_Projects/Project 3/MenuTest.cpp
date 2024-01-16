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

void Menu(vector<Card> userDeck, vector<Card> playDeck, User you, Map map)
{
    //Menu
    bool game = true;
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
            game = false;
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
            cout << "" << endl;
        }
        else if(input == 5)
        {
            cout << "The woods are too much to bear. You give up. You curl up in a ball until the forest takes you..." << endl;
            cout << "Goodbye " << you.getName() <<  ". May we meet again." << endl;
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

int main()
{
    srand(time(0));
    bool game = true;
    while(game == true)
    {
        vector <Card> userDeck;
        vector <Card> playDeck;
        vector <Card> overallDeck;

        Map map;
        Game g;

        User you("Bob");

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

        g.readCards("CardData.txt");
        Card a = g.findCard(1);
        Card b = g.findCard(1);
        Card c = g.findCard(1);
        cout << "This is only a start. Find a way to use them in battle. Good Luck Traveler " << you.getName() << endl;
        you.addCard(a, userDeck);
        you.addCard(b, userDeck);
        you.addCard(c, userDeck);

        //you.displayDeck();

        Menu(userDeck, playDeck, you, map);
    }
}