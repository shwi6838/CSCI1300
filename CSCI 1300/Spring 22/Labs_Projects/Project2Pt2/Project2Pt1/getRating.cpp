#include<iostream>
#include"User.h"
#include"Movie.h"
#include<fstream>
#include<string>

using namespace std:

int getRating(string username, string title, User users[], Movie movies[], int numUsers, int numMovies)
{
    int userindx = -10;
    int titleindx = -10;
    for(int c = 0; c < username.length(); c++) //Username to uppercase
    {
        username[c] = toupper(username[c]);
    }
    for(int d =0; d < title.length(); d++) //Title to uppercase
    {
        title[d] = toupper(title[d]);
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
    for(int j = 0; j < numMovies; j++) //Take each movie title from movies[] and convert to uppercase
    {
        string mov = movies[j].getTitle();
        for(int b = 0; b < mov.length(); b++)
        {
            mov[b] = toupper(mov[b]);
        }
        if(mov == title) //Compare to the target title
        {
            titleindx = j;
        }
    }
    
    if(userindx == -10)
        return -3;
    if(titleindx == -10)
        return -3;

    int rating = users[userindx].getRatingAt(titleindx);
    return rating;
}