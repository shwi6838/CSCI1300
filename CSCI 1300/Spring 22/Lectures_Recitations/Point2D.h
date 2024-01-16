#ifndef Point2D
#define Point2D

class Point2D
{
    public:
        Point2D();

        Point2D(double,double,string);

        //Setters
        void setX(double);
        void setY(double);
        void setLabel(string);

        //Getters
        double getX();
        double getY();
        string getLabel();

        void print();

        double distance(Point2D);

    private:
        double x;
        double y;
        string label;
}

#endif