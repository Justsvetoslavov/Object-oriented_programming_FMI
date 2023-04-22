#include "SelfCounting.h"

size_t SelfCounting::liveObjectCount = 0;
size_t SelfCounting::createdCount = 0;

SelfCounting::SelfCounting() : SelfCounting(0) {}

SelfCounting::SelfCounting(int val) : constValue(val) {
	++liveObjectCount;
	++createdCount;
}

SelfCounting::SelfCounting(const SelfCounting& other) : constValue(other.constValue) {
	++liveObjectCount;
	++createdCount;
}

SelfCounting::~SelfCounting() {
	--liveObjectCount;
}

size_t SelfCounting::getLiveObjectCount() {
	return liveObjectCount;
}

size_t SelfCounting::getCreatedCount() {
	return createdCount;
}