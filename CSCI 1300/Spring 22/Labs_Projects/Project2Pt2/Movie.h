#ifndef Movie
#define Movie

#include<iostream>
using namespace std;

class Movie
{
    public:
        Movie();
        Movie(string, string);

        //Setters
        void setTitle(string);
        void setReleaseYear(string);

        //Getters
        string getTitle();
        string getReleaseYear();

    private:
        string title;
        string releaseYear;
};

#endif