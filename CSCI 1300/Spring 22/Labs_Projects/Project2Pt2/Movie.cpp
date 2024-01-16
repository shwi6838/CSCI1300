#include"Movie.h"

Movie::Movie()
{
    title = "";
    releaseYear = "";
}
Movie::Movie(string newtitle, string newyear)
{
    title = newtitle;
    releaseYear = newyear;
}

//Setters
void Movie::setTitle(string newtitle)
{
    title = newtitle;
}
void Movie::setReleaseYear(string newyear)
{
    releaseYear = newyear;
}

//Getters
string Movie::getTitle()
{
    return title;
}
string Movie::getReleaseYear()
{
    return releaseYear;
}