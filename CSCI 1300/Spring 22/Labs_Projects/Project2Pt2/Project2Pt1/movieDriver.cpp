#include<iostream>
#include"Movie.h"

using namespace std:

int main()
{
    Movie m;
    m.getTitle();
    m.getReleaseYear();
    
    Movie a("Cars, 2006");
    a.getTitle();
    a.getReleaseYear();

    m.setTitle("Bee Movie");
    m.setReleaseYear("2007");
    m.getTitle();
    m.getReleaseYear();
}