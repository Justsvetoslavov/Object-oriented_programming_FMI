#include "HelperFunctions.h"

size_t GetDigitsCount(size_t n)
{
	size_t count = 1;
	while ((n /= 10) != 0) count++;
	return count;
}
