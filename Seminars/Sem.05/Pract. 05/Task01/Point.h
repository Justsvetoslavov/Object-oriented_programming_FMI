#pragma once
class Point
{
private:
	int x;
	int y;

public:
	Point() = default;
	Point(const Point& point) = default;
	Point& operator=(const Point& point) = default;
	~Point() = default;
	explicit Point(int x = 0, int y = 0);
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
	void SetX(double x) = delete;
	void SetY(double y) = delete;
	double GetDistance(int a, int b, int c) const;
};

