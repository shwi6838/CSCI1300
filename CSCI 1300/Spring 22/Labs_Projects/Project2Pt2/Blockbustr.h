#ifndef Blockbustr
#define Blockbustr

#include<iostream>
#include"Movie.h"
#include"User.h"
#include<string>
#include<iomanip>

using namespace std;

class Blockbustr
{

    private:
        const static int sizeMovie = 50;
        const static int sizeUser = 100;
        Movie movies[sizeMovie];
        User users[sizeUser];
        int numMovies;
        int numUsers;


    public:
        Blockbustr();
        // Getters
        int getSizeMovie();
        int getSizeUser();
        int getNumMovies();
        int getNumUsers();
        
        int readMovies(string);
        void printMoviesByYear(string);
        int readRatings(string);
        int getRating(string,string);
        int getCountWatchedMovies(string);
        double calcAvgRating(string);
        int addUser(string);
        int rentMovie(string,string,int);

        //Setters

};

#endif