#pragma once
class FuelTank
{
private:
	double capacity = 0;
	double currentFullness = 0;
public:
	FuelTank() = default;
	FuelTank(unsigned capacity);

	void SetCapacity(double capacity);
	void Use(double toUse);
	void Fill(double toFill);

	double GetCurrentFullnes() const;
};

