#pragma once
#include "Constants.h"

struct Student
{
	char first_name[FIELD_MAX_SIZE];
	char last_name[FIELD_MAX_SIZE];
	char email[FIELD_MAX_SIZE];
	unsigned fn = 0;
};