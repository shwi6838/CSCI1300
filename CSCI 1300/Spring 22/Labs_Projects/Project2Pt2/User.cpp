#include"User.h"

User::User()
{
    username = "";
    numRatings = 0;
    for(int i=0; i<size; i++)
    {
        ratings[i] = 0;
    }
}
User::User(string newUser, int newratings[size], int newRatings)
{
    username = newUser;
    numRatings = newRatings;
    for(int n = 0; n < numRatings; n++)
    {   
        ratings[n] = newratings[n];
    }
    for(int m = numRatings; m < size; m++)
    {
        ratings[m] = 0;
    }
}

//Getters
string User::getUsername()
{
    return username;
}
int User::getRatingAt(int index)
{
    if(index >= size || index < 0)
        return -1;
    else
        return ratings[index];
}
int User::getNumRatings()
{
    return numRatings;
}
int User::getSize()
{
    return size;
}

//Setters
void User::setUsername(string newuser)
{
    username = newuser;
}
bool User::setRatingAt(int index, int value)
{
    if(((value <= 5) && (value >=0)) && ((index < size) && (index >=0)))
    {
        ratings[index] = value;
        return true;
    }
    else
    {
        return false;
    }
}
void User::setNumRatings(int newRatings)
{
    numRatings = newRatings;
}