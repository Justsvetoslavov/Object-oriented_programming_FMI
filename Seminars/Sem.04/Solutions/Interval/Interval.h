class Interval {
private:
	int a;
	int b;
public:
	Interval();
	Interval(int, int);
	
	//Accessors
	int getA() const;
	int getB() const;
        
	//Mutators
	bool setA(int);
	bool setB(int);

	size_t GetLength() const;
	bool IsMemberOfInterval(int) const;

	size_t CalcPrimeNumbersInTheInterval() const;
	size_t CalcPalindromicNumbersInTheInterval() const;
	size_t CalcDiffrentDigitNumbersInTheInverval() const;
	
	bool RreStartAndEndPowersOfTwo() const;
	
	Interval Intersect(const Interval&) const;
	
	bool IsSuperInterval(const Interval&) const;
private:
	size_t CountNumbersInIntervalCondition(bool(*pred)(int)) const;
};
