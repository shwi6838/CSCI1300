#include<iostream>
#include"User.h"
#include"Movie.h"
#include<fstream>
#include<string>

using namespace std:

int getCountWatchedMovies(string username, User users[], int numUsers, int numMovies)
{
    if(numMovies == 0)
        return -3;

    int userindx = -10;
    for(int c = 0; c < username.length(); c++) //Username to uppercase
    {
        username[c] = toupper(username[c]);
    }

    for(int i = 0; i < numUsers; i++) //Take each username in user[] and convert to uppercase
    {
        string name = users[i].getUsername();
        for(int a = 0; a < name.length(); a++)
        {
            name[a] = toupper(name[a]);
        }
        if(name == username) //Compare to the target username
        {
            userindx = i;
        }
    }

    int count=0;
    
    for(int m = 0, m < numMovies; m++)
    {
        if((users[userindx].getRatingAt(m)) != 0)
            count++;
    }

    if(userindx == -10)
        return -3;
    

    return count;
}