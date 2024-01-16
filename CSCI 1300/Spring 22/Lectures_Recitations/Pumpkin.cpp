#include <iostream>

using namespace std;

double fertilize(double stock, double amount)
{
    if(stock < amount)
        return "You do not have enough to fertilize.";
        return (stock - amount);
    else
        return (stock - amount);
}

double restock(double stock, double amount)
{
    return (stock + amount);
}
