#pragma once

class Point {
	int x;
	int y;
public:
	Point() = default;
	Point(int x = 0, int y = 0) = delete; 
	Point(const Point& other) = default;
	Point& operator=(const Point& other) = default;
	~Point() = default;
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
	void SetX(double x) = delete;
	void SetY(double y) = delete;
	int Distance(const Point& p1, const Point& p2) const;
};