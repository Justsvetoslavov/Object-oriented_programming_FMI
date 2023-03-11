#include <iostream>
#include <cmath>
using std:: cout;
using std:: cin;


const int FIRSTQUADRANT = 1;
const int SECONDQUADRANT = 2;
const int THIRDQUADRANT = 3;
const int FOURTHQUADRANT = 4;

struct Point
{
    double x; 
    double y;
};

void initNewPoint(Point& point)
{
    cout << "x = ";
    cin >> point.x;
    cout << "y = ";
    cin >> point.y; 
}

void printPoint(const Point& point)
{
    cout << "(" << point.x << ", " << point.y << ")\n";
}

double distanceCentre(const Point& point)
{
    return sqrt(pow(point.x, 2) + pow(point.y, 2));
}

double distanceBetweenTwoPoints(const Point& firstPoint, const Point& secondPoint)
{
    return sqrt(pow(firstPoint.x -secondPoint.x, 2) + pow(firstPoint.y - secondPoint.y, 2));
}

int Quadrant(const Point& point)
{
    double x = point.x;
    double y = point.y;

    if(x == 0 || y == 0)
    {
        return 0;
    }
    else if(x>0)
    {
        if(y>0)
        {
            return FIRSTQUADRANT;
        }
        else
        {
            return FOURTHQUADRANT;
        }

    }
    else
    {
        if(y>0)
        {
            return SECONDQUADRANT;
        }
        else
        {
            return THIRDQUADRANT;
        }
    }
}

bool isInTheCyrcleOrOnIt(const double& r, const Point& point)
{
    if(distanceCentre(point) < r || distanceCentre(point) == r)
    {
        return true;
    }
    
    return false;
}

int main()
{
    Point point;
    initNewPoint(point);
    printPoint(point);
    cout << "Distance from the centre (0.0, 0.0): " << distanceCentre(point) <<'\n';
    const Point secondPoint = {4.6, 3.7};
    cout << "Distance between the two points (Yours and (4.6, 3.7)): " << distanceBetweenTwoPoints(point, secondPoint) << '\n';
    double r = 7.3;
    cout << "Is the point in/on the cyrcle with radios 7.3 (1 - yes, 0 - no): " << isInTheCyrcleOrOnIt(r, point) << '\n';
    cout << "The point is in " << Quadrant(point) << " quadrant \n";
}