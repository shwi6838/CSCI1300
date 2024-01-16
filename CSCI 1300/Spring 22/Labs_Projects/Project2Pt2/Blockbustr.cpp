#include"Blockbustr.h"

Blockbustr::Blockbustr()
{
    numMovies = 0;
    numUsers = 0;
}
int Blockbustr::getSizeMovie()
{
    return sizeMovie;
}
int Blockbustr::getSizeUser()
{
    return sizeUser;
}
int Blockbustr::getNumMovies()
{
    return numMovies;
}
int Blockbustr::getNumUsers()
{
    return numUsers;
}

string toLower(string s) //Changes a string to all lowercase letters by letter
{
    for(int i = 0; i < s.length(); i++)
    {
        if((s[i] >= 'A')&&(s[i]<='Z'))
        {
            s[i] = s[i]+32;
        }
    }
    return s;
}

int split(string inputString, char separator, string arr[],int size)
{
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

int Blockbustr::readMovies(string file) 
{
    ifstream fin; // create an input file stream object
    fin.open(file); // open file.txt with the file stream object

    //int numMovies = getNumMovies();
    if(numMovies >= sizeMovie) 
        return -2;
    
    if(fin.fail()) //Checks if file was not opened
        return -1;
    
    string line = ""; 
    string arr[2];
    int row = numMovies; //Accounts for movies already in database
    while (!fin.eof())
    {
            getline(fin, line);
            if(split(line, ',', arr, 2)) //Splits each line
            {
                Movie mov(arr[0], arr[1]); //Creates movie object using new array
                
                movies[row] = mov; //Adds movie to movie array
                row++; //Adds to row index
                numMovies++; //Adds to number of movies stored
                if(row == 50) //Checks if movie array is full
                    return row;
            }
    }
    
    return row;
}

void Blockbustr::printMoviesByYear(string releaseYear)
{
    //int numMovies = getNumMovies();
    int count = 0;
    if(numMovies <= 0) //Checks for zero movies
    {
        cout << "No movies are stored" << endl;
    }
    else
    {
        for(int i = 0; i < numMovies; i++)
        {
            if(movies[i].getReleaseYear() == releaseYear) //Checks for each movie in array and compares release year to target year
                count ++; //Counts every matching year
        }

        if(count == 0) //There are no movies matching
            cout << "There are no stored movies released in " << releaseYear << endl;
        else //Movies were found
            cout << "Here is a list of movies released in " << releaseYear << endl;

        for(int i = 0; i < numMovies; i++)
        {
            if(movies[i].getReleaseYear() == releaseYear)
            {
                cout << movies[i].getTitle() << endl; //Lists every movie in database with the target release year
            }
        }
    }
}

int Blockbustr::readRatings(string file)
{
    ifstream fin; // create an input file stream object
    fin.open(file); // open file.txt with the file stream object

    //int numUsers = getNumUsers();
    if(numUsers >= sizeUser) //Checks for incorrect user data
        return -2;

    if(fin.fail()) // Checks for failure of opening file
        return -1;

    string line = "";
    string arr[51];
    int row = numUsers; //Accounts for existing users in database
    while (!fin.eof())
    {
        getline(fin, line);
        if(split(line, ',', arr, 51))
        {
            string userHold = arr[0]; //Holds the name of user in a string

            int rating[50];
            int numRating = 0; 
            for(int i = 1; i < 51; i++)
            {
                if(arr[i] != "") //Checks for empty ratings
                {
                    rating[i-1] = stoi(arr[i]); //Adds rating into empty spaces and adds to counter
                    numRating++;
                }
            }
            

            User u1 = User(userHold,rating,numRating); //Creates new user
            users[row] = u1; //Adds to user array
            row++;
            numUsers++; //Adds to user counter and updates row

            if(row == sizeUser) //Checks for full array
                return row;
        }
    }
    return row; //Return number of ratings
}

int Blockbustr::getRating(string username ,string title)
{
    int userindx = -10;
    int titleindx = -10;
    username = toLower(username);
    title = toLower(title); //Creates lowercase strings

    for(int i = 0; i < numUsers; i++) //Take each username in user[] and convert to lowercase
    {
        string name = users[i].getUsername(); //Saves names as strings
        name = toLower(name);
        if(name == username) //Compare to the target username
        {
            userindx = i; //Saves index of target user
        }
    }
    for(int j = 0; j < numMovies; j++) //Take each movie title from movies[] and convert to lowercase
    {
        string mov = movies[j].getTitle();
        mov = toLower(mov);
        if(mov == title) //Compare to the target title
        {
            titleindx = j; //Saves index of target movie
        }
    }
    
    if(userindx == -10) //Checks if the index didn't change (User or movie not found)
        return -3;
    if(titleindx == -10)
        return -3;

    int rating = users[userindx].getRatingAt(titleindx); //Gets rating for user at index of the title
    return rating;
}

int Blockbustr::getCountWatchedMovies(string username)
{
    //int numMovies = getNumMovies();
    if(numMovies == 0)
        return -3;

    int userindx = -10;
    username = toLower(username);

    for(int i = 0; i < numUsers; i++) //Take each username in user[] and convert to uppercase
    {
        string name = users[i].getUsername();
        name = toLower(name);
        if(name == username) //Compare to the target username
        {
            userindx = i; //Saves index of user
        }
    }

    int count=0;
    
    for(int m = 0; m < numMovies; m++)
    {
        if((users[userindx].getRatingAt(m)) != 0) //Adds to counter when the rating exists and is not zero
            count++;
    }

    if(userindx == -10) //Check for no ratings
        return -3;
    

    return count;
}

double Blockbustr::calcAvgRating(string title)
{
    double sum = 0;
    double avg;
    int count = 0;
    int rate;
    string movieSub;
    string userSub;
    bool validUser = false;
    bool validMovie = false;
    string movie = toLower(title);

    if(getNumUsers()==0)
        return -3;
    
    for(int i = 0; i < 50; i++)
    {
        movieSub = movies[i].getTitle();
        movieSub = toLower(movieSub);
        if(movieSub == movie)
        {
            validMovie = true;
            break;
        }
    }
    if(validMovie == false)
        return -3;
    
    //int numUsers = getNumUsers();
    for(int j = 0; j < numUsers; j++)
    {
        userSub = users[j].getUsername();
        rate = getRating(userSub, title);
        if((rate > 0)&&(rate <=5))
        {
            count++;
            sum += rate;
        }
        else
        {
            rate = 0;
        }
    }

    if(validMovie == true)
    {
        if((sum == 0) && (count == 0))
            return 0;
        else
            avg = sum / count;
        
        return avg;
    }
}

int Blockbustr::addUser(string username)
{
    int UserCount;
    username = toLower(username);
    string u;
    for(int i = 0; i < numUsers; i++)
    {
        u = toLower(users[i].getUsername());
        if(username == u)
            return 0;
    }
    if(numUsers == 100)
        return -2;
    else
    {
        users[numUsers].setUsername(username);
        numUsers++;
        return 1;
    }
}

int Blockbustr::rentMovie(string username,string title,int rating)
{
    bool validUser = false;
    bool validMovie = false;
    bool validRating = false;
    string user1;
    string movie1;
    int userindx;
    int movieindx;

    username = toLower(username);
    title = toLower(title);
    if((rating < 0) || (rating > 5))
        return -4;
    else
        validRating = true;
    
    for(int i = 0; i < 100; i++)
    {
        user1 = toLower(users[i].getUsername());
        if(username == user1)
        {
            validUser = true;
            userindx = i;
        }
    }
    for(int j = 0; j< 50; j++)
    {
        movie1 = toLower(movies[j].getTitle());
        if(title == movie1)
        {
            validMovie = true;
            movieindx = j;
        }
    }
    if((validUser == true)&&(validMovie == true)&&(validRating == true))
    {
        users[userindx].setRatingAt(movieindx, rating);
        return 1;
    }
    else
        return -3; 
}