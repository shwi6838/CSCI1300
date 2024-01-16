#include<iostream>
#include"Point2D.h"

using namespace std:

int main()
{
    Point2D p; //calls the default constructor
    p.print(); 

    Point2D q(3, 4, "Q");
    q.print();

    Point2D r(-10, 4); //uses the parameterized constructor
    r.print();
    r.setLabel("R"); //can also use setters to update data members
    r.print();

    cout << "q.distance(p): " << q.distance(p) << endl;
    cout << "r.distance(q): " << r.distance(q) << endl;
}