#pragma once
class Point {
private:
	int x;
	int y;

public:
	Point() = default;
	Point(int all) = delete;
	explicit Point(int x = 0, int y = 0);
	Point(const Point& other) = default;
	Point& operator=(Point& other) = default;
	~Point() = default;

	int getX() const;
	int getY() const;

	void setX(int x);
	void setY(int y);

	void setX(double x) = delete;
	void setY(double y) = delete;

	double getDist(int a, int b, int c);
};

