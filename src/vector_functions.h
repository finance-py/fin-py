#ifndef VECTORFUNCTIONS_H
#define VECTORFUNCTIONS_H

#include <vector>
#include <algorithm>

template <typename T> int IsIn(std::vector<T> vect, T value)
{
	// check if the value is in the vector at all
	if (std::find(vect.begin(), vect.end(), value) == vect.end())
	{
		return -1;
	}

	auto it = std::find(vect.begin(), vect.end(), value);

	int idx = it - vect.begin();

	return idx;
}

#endif