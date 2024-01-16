#include<iostream>
#include"User.h"
#include"Movie.h"
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int split(string inputString, char separator, string arr[],int size){
    
    arr[0]=inputString;
    int index=0; // index of the array
    int sepIndex=0; // index of the last separator found

    if(inputString=="") // check for empty input
    {
        return 0;
    }

    for(int i=0;i<inputString.length()+1;i++) // loop through input
    {
        if(inputString[i]==separator) //If separator is found
        {
            arr[index]=inputString.substr(sepIndex,i-sepIndex); //Add word created between separators at the index of the array
            sepIndex=i+1; // increase the separator index to start the next word 
            if(size==index+1) //check for bounds in size
            {
                return -1;
            }
            arr[index+1]=inputString.substr(sepIndex,i); //set up next index to start next word
            index++; //increase the index for array
        }
    }
    return index+1; //TReturns the number of splits + 1 to equal the number of words
}

int readRatings(string file, User users[], int numUsers, int userArrSize, int maxRatings)
{
    ifstream fin; // create an input file stream object
    fin.open(file); // open file.txt with the file stream object

    if(numUsers >= userArrSize)
        return -2;

    if(fin.fail())
        return -1;

    string line = "";
    string arr[51];
    int row = numUsers;
    while (!fin.eof())
    {
        getline(fin, line);
        if(split(line, ',', arr, 51))
        {
            string user = arr[0];

            int rating[50];
            int numRating = 0;
            for(int i = 1; i < maxRatings+1; i++)
            {
                if(arr[i] != "")
                {
                    rating[i-1] = stoi(arr[i]);
                    numRating++;
                }
            }
            

            User u1 = User(user,rating,numRating);
            users[row] = u1;
            row++;

            if(row == userArrSize)
                return userArrSize;
        }
    }
    return row;
}

int readMovies(string file, Movie movies[], int numMovie, int movieArrSize)
{
    ifstream fin; // create an input file stream object
    fin.open(file); // open file.txt with the file stream object

    if(numMovie >= movieArrSize)
        return -2;
    
    if(fin.fail())
        return -1;

    string line = "";
    string arr[2];
    int row = numMovie;
    while (!fin.eof())
    {
            getline(fin, line);
            if(split(line, ',', arr, 2))
            {
                Movie mov(arr[0], arr[1]);
                
                movies[row] = mov;
                row++;
                if(row == movieArrSize)
                    return row;
            }
    }
    return row;
}

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
    
    for(int m = 0; m < numMovies; m++)
    {
        if((users[userindx].getRatingAt(m)) != 0)
            count++;
    }

    if(userindx == -10)
        return -3;

    return count;
}

int main()
{
    Movie movies[50];
    User users[100];
    int numUsers =0;
    int numMovies = 0;

    bool go = true;
    while (go == true)
    {
        cout << "======Main Menu=====" << endl;
        cout << "1. Read movies" << endl;
        cout << "2. Read ratings" << endl;
        cout << "3. Print movies by year" << endl;
        cout << "4. Get rating" << endl;
        cout << "5. Find number of movies user rated" << endl;
        cout << "6. Quit" << endl;

        int input;
        cin >> input;
        switch(input)
        {
            case 1:
            string file ="";
            cout << "Enter a movie file name: "
            cin >> file;

            int x = readMovies(file, movies, numMovies, 50);
            if(x == -1)
                cout << "No movies saved to the database." << endl;
            else if(x == -2)
                cout << "Database is already full. No movies were added." << endl;
            else if(x == 50)
            {
                cout << "Database is full. Some movies may have not been added." << endl;
                numMovies = numMovies + x;
            }
            else
            {
                cout << "Total movies in the database: " << x << endl;
                numMovies+ numMovies + x;
            }
            break;

            case 2:
            string file ="";
            cout << "Enter a movie file name: "
            cin >> file;

            int x = readRatings(file, users, numUsers, 100, 50);
            if(x == -1)
            cout << "No users saved to the database." << endl;
            else if(x == -2)
                cout << "Database is already full. No users were added." << endl;
            else if(x == 50)
            {
                cout << "Database is full. Some users may have not been added." << endl;
                numUsers += x;
            }
            else
            {
                cout << "Total users in the database: " << x << endl;
                numUsers +=x;
            }
            break;

            case 3:
            string year;
            cout << "Enter release year of movie:" << endl;
            cin >> year;

            printMoviesByYear(movies, numMovies, year);
            break;

            case 4:
            string name;
            string title;
            cout << "Enter a user name:" << endl;
            cin >> name;
            cin.ignore();
            cout << "Enter a movie title:" << endl;
            getline(cin, title);

            int rating = getRating(name, title, users, movies, numUsers, numMovies);
            if(rating == 0)
                cout << name << " has not rated "<< title << endl;
            else if(rating == -3)
                cout << name << " or "<< title << " does not exist." << endl;
            else
                cout << name << " rated " << title << " with " << rating << endl;
            break;

            case 5:
            string name;
            cout << "Enter a user name:" << endl;
            cin >> name;

            int x = getCountWatchedMovies(name, users, numUsers, numMovies);
            if(x == 0)
                cout << name << " has not rated any movies." << endl;
            else if(x == -3)
                cout << name << " does not exist." << endl;
            else
                cout << name << " rated "<< x << " movies." << endl;
            break;

            case 6: 
            cout << "Good bye!" << endl;
            go = false;
            break;

            default: 
            cout << "Invalid input." << endl;
        }
    }
}