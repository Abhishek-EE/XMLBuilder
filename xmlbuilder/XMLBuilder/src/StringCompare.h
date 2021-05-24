#pragma once
#include<string>
//This is a code for comparing string in the STL map
struct cmp_str
{
	bool operator()(char const *a, char const *b) const
	{
		return std::strcmp(a, b) < 0;
	}
};