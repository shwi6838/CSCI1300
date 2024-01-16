#ifndef User
#define User

#include<iostream>
#include<string>
#include<iomanip>
using namespace std:

class User
{
    private:
        const static int size = 50;
        string username;
        int ratings[size];
        int numRatings;
    
    public:
        User();
        User(string, int[size], int);

        //Getters
        string getUsername();
        int getRatingAt(int);
        int getNumRatings();
        int getSize();

        //Setters
        void setUsername(string);
        bool setRatingAt(int, int);
        void setNumRatings(int);

};

#endif