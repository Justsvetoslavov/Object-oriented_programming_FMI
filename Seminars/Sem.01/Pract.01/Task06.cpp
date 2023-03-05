// ConsoleApplication33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Point {
	int x;
	int y;
};
double Lenght(const Point& p1, const Point& p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.y) + (p1.y - p2.y) * (p1.y - p2.y));
}
double lenghtFromCenter(const Point& p1) {
	return sqrt((p1.x) * (p1.x) + (p1.y) * (p1.y));
}
void quadrantPlacement(const Point& p) {
	if (p.x == 0 && p.y == 0) {
		cout << "The Point is in the center."<<endl;
	}
	if (p.x < 0 && p.y < 0) {
		cout << "The Third Point is in the third quadrant" << endl;
	}
	if (p.x > 0 && p.y > 0) {
		cout << "The Third Point is in the first quadrant" << endl;
	}
	if (p.x > 0 && p.y < 0) {
		cout << "The Third Point is in the fouth quadrant" << endl;
	}
	if (p.x < 0 && p.y > 0) {
		cout << "The Third Point is in the second quadrant" << endl;
	}
}
void radius(const Point& k,const int radius) {
	if (k.x > radius || k.y > radius) {
		cout << "Point K doesn't belong to the area.";
	} 
	else {
		cout << "Point K belongs to the area.";
	}
}
int main()
{
	Point p1, p2, p3,K;
	int r;
	cout << "Enter the cordinates for the first point : x = ";
	cin >> p1.x;
	cout << "y = ";
	cin >> p1.y;
	cout << "Enter the cordinates for the first point : x = ";
	cin >> p2.x;
	cout << "y = ";
	cin >> p2.y;
	cout << "Enter the coordinates for a third point: x = ";
	cin >> p3.x;
	cout << "y = ";
	cin >> p3.y;
	cout << "Enter the coordinates for point K: x = ";
	cin >> K.x;
	cout << "y = ";
	cin >> K.y;
	cout << "Enter a radius for point K : r = ";
	cin >> r;
	cout << "The lenght between the two points is " << Lenght(p1, p2) << " cms" << endl;
	cout << "The lenght between the center and the first point is " << lenghtFromCenter(p1) << " cms" << endl;
	cout << "The lenght between the center and the second point is " << lenghtFromCenter(p2) << " cms" << endl;
	quadrantPlacement(p3);
	radius(K, r);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
