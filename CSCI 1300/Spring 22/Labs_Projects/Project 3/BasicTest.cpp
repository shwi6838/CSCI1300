#include "Game.h"
#include "Table.h"
#include "User.h"
#include "Card.h"
#include "Map.h"
#include"Enemy.h"
#include <time.h>

using namespace std;

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

int main()
{
    srand(time(0));
    vector<Card> userDeck;
    vector<Card> Deck;
    vector<Card> playDeck;
    Card TableData[2][4];

    Game game;

    Card c("Bear", 3, 2, 2);
    Card d("Cat", 2, 2, 1);

    c.setHealth(4);

    c.displayCard();

    User u;
    u.setName("Dobby");
    u.addCard(c, userDeck);
    u.addCard(d, userDeck);

    u.displayDeck(userDeck);
    int num = u.getNumCards();
    cout << num << endl;

    u.removeCard(c,userDeck);
    num = u.getNumCards();
    cout << num << endl;
    u.resetDeck(userDeck);

    Enemy e("King Pin", 2);
    cout << e.getName() << endl;
    e.setName("Not King Pin");
    cout << e.getName() << endl;
    int level = e.getDifficulty();
    e.fillDeck(level, game);


    Table battle1;
    battle1.setName("Battle 1");

    battle1.displayTable();
    u.addCard(c,playDeck);
    Card g = e.getRandomCard();
    battle1.placeCard(c, 2, 2);
    battle1.placeCard(g,1,2);

    battle1.getCardAt(2,2);
    battle1.displayTable();
    cout << battle1.getName() << endl;
    //battle1.killCard();
    e.resetDeck();

    Map m;
    m.readMapData("MapData.txt");
    m.displayMap();
    int row = m.getUserRow();
    int col = m.getUserCol();
    m.fillRandomEvent();
    int moves = m.Branches();

    m.setUserPos(16,7);
    moves = m.Branches();

    Card n = game.findCard(1);
    u.addCard(n, userDeck);

    Card f = game.findCard(1);
    u.addCard(f,userDeck);

    Card merged = game.mergeCards(n, f, n.getName());
    u.addCard(merged, userDeck);

    u.displayDeck(userDeck);

}