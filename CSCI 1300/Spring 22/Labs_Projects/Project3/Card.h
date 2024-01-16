#ifndef Card
#define Card

#include<iostream>
using namespace std;

class Card
{
    public:
        Card();
        Card(string, int, int, int);

        //Setters
        void setName(string);
        void setDamage(int);
        void setHealth(int);
        void setLevel(int);

        //Getters
        string getName();
        int getDamage();
        int getHealth();
        int getLevel();

        void displayCard();

    private:
        string name;
        int health;
        int damage;
        int level;
};

#endif