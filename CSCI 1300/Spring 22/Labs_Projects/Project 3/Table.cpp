#include "Table.h"
#include"Card.h"
#include "User.h"

Table::Table()  //Creates empty Table Array and sets points to zero
{
    tname = "";
    Userpoints = 0;
    Enemypoints = 0;
    for(int row = 0; row < 2; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            TableData[row][col] = Card();
        }
    }
}

void Table::displayTable()  //Displays an array of Card objects, with the empty card spaces as well
{
    //Similar to a deck of displayed cards
    //Display a ? on an empty space with no card
    cout << tname << "'s Battle" << endl;
    for(int row = 0; row < 2; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            Card d = TableData[row][col];
            if(d.getName() == "")
                cout << "? \n? \n? " << endl;
            else
                d.displayCard();
        }
    }
    cout << endl;
    cout << "User: " << Userpoints << endl;
    cout << "Enemy: " << Enemypoints << endl;
}

//Getters
string Table::getName()
{
    return tname;
}

Card Table::getCardAt(int row,int col)  //Return card object at specified index on the 2D array table
{
        Card c = TableData[row][col];
        c.displayCard();
        return c;
}

int Table::getCardRow(Card c)  //Return the row index of a card on table
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            Card d = TableData[i][j];
            if(d.getName() == c.getName())
            {
                return i;
            }
        }
    }
    return -1;
}

int Table::getCardCol(Card c)  //Return the col index of a card on table
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            Card d = TableData[i][j];
            if(d.getName() == c.getName())
            {
                return j;
            }
        }
    }
    return -1;
}

int Table::getEnpoints()
{
    return Enemypoints;
}
int Table::getUserpoints()
{
    return Userpoints;
}

//Setters
void Table::setName(string name_)
{
    tname = name_;
}

bool Table::placeCard(Card c, int row, int col) //Fills specified index of 2D array on table with a card object c
{
    if(TableData[row][col].getName() == "")
    {
        TableData[row][col] = c;
        return true;
    }
    return false;
}

void Table::killCards()  //Takes card out of 2D table array and leaves an empty Card (?) if card has 0 health
{
    for(int row = 0; row < 2; row++)
    {
        for(int col = 0; col < 4; col++)
        {
            if(TableData[row][col].getHealth() == 0)
            {
                TableData[row][col] = Card();
            }
        }
    }
}

void Table::setEnpoints(int p)
{
    Enemypoints = p;
}
void Table::setUserpoints(int p)
{
    Userpoints = p;
}

void Table::battleCards()  //Compares Damages and Healths of Cards on the Table and adjusts each sides points
{
    int Upoints;
    int Epoints;
    for(int col = 0; col < 4; col++)
    {
        Upoints += (TableData[1][col].getDamage() - TableData[0][col].getHealth());
        Epoints += (TableData[0][col].getDamage() - TableData[1][col].getHealth());
    }
}