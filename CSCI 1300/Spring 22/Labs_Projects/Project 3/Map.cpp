#include"Map.h"
#include<fstream>
#include<string>

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
    return index+1; //Returns the number of splits + 1 to equal the number of words
}

Map::Map()
{
    //Creates Empty Map array
    for(int row = 0; row < Mrows; row++)
    {
        for(int col = 0; col < Mcols; col++)
        {
            MapData[row][col] = '-';
        }
    }
    //Set User position to bottom middle start point
    MapData[38][7] = 'X';
}

bool Map::readMapData(string file)
{
    //Reads from file and fills map array with landscape, paths, and empty nodes by character 'O'
    ifstream fin; // create an input file stream object
    fin.open(file); // open file.txt with the file stream object
    
    if(fin.fail()) //Checks if file was not opened
        return false;
    
    string line = ""; 
    string arr[15];
    int i = 0;
    while (!fin.eof())
    {
            getline(fin, line);
            if(split(line, ',', arr, 15)) //Splits each line
            {
                for(int col = 0; col < 15; col++)
                {
                    MapData[i][col] = arr[col].at(0);
                }
                i++; //Adds to row index
            }
    }
    return true;
}

void Map::displayMap()
{
    //Print the full array
    //Letters will show what events are where
    //Player will be shown by an X
    for(int row = 0; row < Mrows; row++)
    {
        for(int col = 0; col < Mcols; col++)
        {
            cout << MapData[row][col];
        }
        cout << endl;
    }
    cout << "Player is shown by an X" << endl;
}

//Getters
int Map::getUserRow()
{
    //Return the row index int value of the players position
    for(int row = 0; row < Mrows; row++)
    {
        for(int col = 0; col < Mcols; col++)
        {
            if(MapData[row][col] == 'X')
            {
                return row;
            }
        }
    }
    return 0;
}

int Map::getUserCol()
{
    //Return the col index int value of the players position
    for(int row = 0; row < Mrows; row++)
    {
        for(int col = 0; col < Mcols; col++)
        {
            if(MapData[row][col] == 'X')
            {
                return col;
            }
        }
    }
    return 0;
}

char Map::getCharNode(int row, int col)
{
    //Return the character at the next node at specified location
    char q = MapData[row][col];
    if((q == 'N') || (q == 'H') || (q == 'D') || (q == 'M') || (q == 'S') || (q == 'F') || (q == 'B'))
    {
        return MapData[row][col];
    }
    else
    {
        return 'x';
    }
    return 'x';
}

int Map::Branches()
{
    //Return the number of branches (1, 2, or 3) that can be taken from the players position
    //Checks for branch data on the map directly around the player position
    // "/" is a right branch, "|" is a forward branch, "\" is a left branch, "_" marks a branch depending on location
    //Int value will determine what moves player can make
    int row = getUserRow();
    int col = getUserCol();
    int branches = 0;
    if((MapData[row-1][col-1] == '\\'))
    {
        //cout << "Move Left" << endl;
        branches++;
    }
    if((MapData[row-1][col] == '|'))
    {
        //cout << "Move Forward" << endl;
        branches++;
    }
    if((MapData[row-1][col+1] == '/'))
    {
        //cout << "Move Right" << endl;
        branches++;
    }
    return branches;
}

//Setters
bool Map::setEvent(int row, int col, char event)
{
    //Sets an event at specified index
    //Can only replace nodes
    //letters mean different events
    if((event != 'N') || (event != 'H') || (event != 'D') || (event != 'M') || (event != 'S') || (event != 'F'))
    {
        cout << "Thats not a valid event." << endl;
        return false;
    }
    else
    {
        MapData[row][col] = event;
        return true;
    }
    return false;
}

void Map::fillRandomEvent()
{
    //Loops through map array and stops at every empty node
    //Gets a random character from the list of event chars
    //Sets the random char at every empty node
    //Chars represent different events
    for(int row = 0; row < Mrows; row++)
    {
        for(int col = 0; col < Mcols; col++)
        {
            if(MapData[row][col] == 'O')
            {
                char event = eventChars[rand() % 5];
                MapData[row][col] = event;
            }
        }
    }
}

bool Map::setUserPos(int row, int col)
{
    //Sets previous spot to empty node
    MapData[getUserRow()][getUserCol()] = 'O';
    //Set player location at specified index (At a node)
    char q = MapData[row][col];
    if((q == 'N') || (q == 'H') || (q == 'D') || (q == 'M') || (q == 'S') || (q == 'F') || (q == 'B'))
    {
        MapData[row][col] = 'X';
        return true;
    }
    else
    {
        return false;
    }
    return false;
}