#include<iostream>
#include"Movie.h"
#include<fstream>
#include<string>

using namespace std:

void printMoviesByYear(Movie movies[], int numMovies, string releaseYear)
{
    int count = 0;
    if(numMovies <= 0)
    {
        cout << "No movies are stored" << endl;
    }
    else
    {
        for(int i = 0; i < numMovies; i++)
        {
            if(movies[i].getReleaseYear() == releaseYear)
                count ++;
        }

        if(count == 0)
            cout << "There are no stored movies released in " << releaseYear << endl;
        else
            cout << "Here is a list of movies released in " << releaseYear << endl;

        for(int i = 0; i < numMovies; i++)
        {
            if(movies[i].getReleaseYear() == releaseYear)
            {
                cout << movies[i].getTitle() << endl;
            }
        }
    }
}