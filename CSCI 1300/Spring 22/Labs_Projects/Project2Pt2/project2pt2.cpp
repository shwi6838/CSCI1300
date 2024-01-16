#include"Blockbustr.h"
#include"User.h"
#include"Movie.h"
#include<fstream>
#include<string>
#include<iomanip>
#include<iostream>

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

int main()
{
    Movie movies[50];
    User users[100];
    Blockbustr b();

    bool go = true;
    while (go == true)
    {
        cout << "======Main Menu=====" << endl;
        cout << "1. Read movies" << endl;
        cout << "2. Read ratings" << endl;
        cout << "3. Print movies by year" << endl;
        cout << "4. Get rating" << endl;
        cout << "5. Find number of movies user rated" << endl;
        cout << "6. Get average rating" << endl;
        cout << "7. Add a user" << endl;
        cout << "8. Rent a movie" << endl;
        cout << "9. Quit" << endl;

        int input;
        cin >> input;
        
        if(input == 1)
        {
            string file;
            cout << "Enter a movie file name: " << endl;
            cin >> file;

            int x = b.readMovies(file);
            if(x == -1)
                cout << "No movies saved to the database." << endl;
            else if(x == -2)
                cout << "Database is already full. No movies were added." << endl;
            else if(x == 50)
            {
                cout << "Database is full. Some movies may have not been added." << endl;
            }
            else
            {
                cout << "Total movies in the database: " << x << endl;
            }
        }

        else if(input == 2)
        {
            string file;
            cout << "Enter a movie file name: " << endl;
            cin >> file;

            int x = b.readRatings(file);
            if(x == -1)
            cout << "No users saved to the database." << endl;
            else if(x == -2)
                cout << "Database is already full. No users were added." << endl;
            else if(x == 50)
            {
                cout << "Database is full. Some users may have not been added." << endl;
            }
            else
            {
                cout << "Total users in the database: " << x << endl;
            }
        }

        else if(input == 3)
        {
            if((b.getNumMovies()==0)||(b.getNumUsers()==0))
            {
                cout << "Database has not been fully initialized." << endl;
                break;
            }
            string year;
            cout << "Enter release year of movie:" << endl;
            cin >> year;

            b.printMoviesByYear(year);
        }

        else if(input == 4)
        {
            if((b.getNumMovies()==0)||(b.getNumUsers()==0))
            {
                cout << "Database has not been fully initialized." << endl;
                break;
            }
            string name;
            string title;
            cout << "Enter a user name:" << endl;
            cin >> name;
            cin.ignore();
            cout << "Enter a movie title:" << endl;
            getline(cin, title);

            int rating = b.getRating(name, title);
            if(rating == 0)
                cout << name << " has not rated "<< title << endl;
            else if(rating == -3)
                cout << name << " or "<< title << " does not exist." << endl;
            else
                cout << name << " rated " << title << " with " << rating << endl;
        }

        else if(input == 5)
        {
            if((b.getNumMovies()==0)||(b.getNumUsers()==0))
            {
                cout << "Database has not been fully initialized." << endl;
                break;
            }
            string name;
            cout << "Enter a user name:" << endl;
            cin >> name;

            int x = b.getCountWatchedMovies(name);
            if(x == 0)
                cout << name << " has not rated any movies." << endl;
            else if(x == -3)
                cout << name << " does not exist." << endl;
            else
                cout << name << " rated "<< x << " movies." << endl;
        }

        else if(input == 6)
        {
            if((b.getNumMovies()==0)||(b.getNumUsers()==0))
            {
                cout << "Database has not been fully initialized." << endl;
                break;
            }
            string title;
            cout << "Enter a movie title:" << endl;
            getline(cin, title);

            double rating = b.calcAvgRating(title);
            if(rating == -3)
            {
                cout << title << " does not exist." << endl;
            }
            else
            {
                cout << "The average rating for" << title << " is " << rating << endl;
            }
        }

        else if(input == 7)
        {
            string name;
            cout << "Enter a user name:" << endl;
            cin >> name;

            if(b.addUser(name)==1)
                cout << "Welcome to Blockbustr " << name << endl;
            else if(b.addUser(name)==0)
                cout << name << " already exists in the database." << endl;
            else if(b.addUser(name)==-2)
                cout << "Database is already full. " << name <<  " was not added." << endl;
        }

        else if(input == 8)
        {
            if((b.getNumMovies()==0)||(b.getNumUsers()==0))
            {
                cout << "Database has not been fully initialized." << endl;
                break;
            }
            string name;
            string title;
            int rating;
            cout << "Enter a user name:" << endl;
            cin >> name;
            cin.ignore();
            cout << "Enter a movie title:" << endl;
            getline(cin, title);
            cin.ignore();
            cout << "Enter a new rating:" << endl;
            cin >> rating;

            if(b.rentMovie(name,title,rating)==1)
                cout << "We hope you enjoyed your movie. The rating has been updated." << endl;
            else if(b.rentMovie(name,title,rating)==-4)
                cout <<  rating << " is not valid." << endl;
            else if(b.rentMovie(name,title,rating)==-3)
                cout << name << "or" << title << " does not exist." << endl;
        }

        else if(input == 9)
        {
            cout << "Good bye!" << endl;
            go = false;
        }

        else
        {
            cout << "Invalid input." << endl;
        }
    }
}