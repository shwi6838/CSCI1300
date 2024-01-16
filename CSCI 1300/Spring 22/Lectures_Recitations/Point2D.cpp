#include"Point2D.h"
#include<cmath>

Point2D()
{
    x = 0.0;
    y = 0.0;
    label = "";
}

Point2D(double newX, double newY, string newLabel)
{
    x = newX;
    y = newY;
    label = newLabel;
}

//Setters
void setX(double newX)
{
    x = newX;
}
void setY(double newY)
{
    y = newY;
}
void setLabel(string newLabel)
{
    label = newLabel;
}

//Getters
double getX()
{
    return x;
}
double getY()
{
    return y;
}
string getLabel()
{
    return label;
}

void print();
{
    if(label == "")
        cout << "(" << x << "," << y << ")" << endl;
    else
        cout << label << ": (" << x << "," << y << ")" << endl;
}

double distance(Point2D b)
{
    double distance = sqrt(pow((x - b.getX()),2) + pow((y - b.getY()),2));
    return distance;
}
