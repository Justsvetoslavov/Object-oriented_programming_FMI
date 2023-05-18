#pragma once

class SelfCounting {
private:
	const int constValue;

	static size_t liveObjectCount;
	static size_t createdCount;
public:
	SelfCounting();
	SelfCounting(int val);
	SelfCounting(const SelfCounting& other);
	~SelfCounting();

	static size_t getLiveObjectCount();
	static size_t getCreatedCount();
};
