#include "Card.h"

Card::Card()
{
    name = "";
    damage = 0;
    health = 0;
    level = 0;
}

Card::Card(string name_, int damage_, int health_, int level_)
{
    name = name_;
    damage = damage_;
    health = health_;
    level = level_;
}

//Setters
void Card::setName(string name_)
{
    name = name_;
}

void Card::setDamage(int damage_)
{
    damage = damage_;
}

void Card::setHealth(int health_)
{
    health = health_;
}

void Card::setLevel(int level_)
{
    level = level_;
}

//Getters
string Card::getName()
{
    return name;
}

int Card::getDamage()
{
    return damage;
}

int Card::getHealth()
{
    return health;
}

int Card::getLevel()
{
    return level;
}

void Card::displayCard() //How cards will be displayed on the deck or on battle table
{
    cout << level << " " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Damage: " << damage << endl;
}
