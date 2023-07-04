#pragma once

#include <vector>
#include <algorithm>
#include "Combination.h"
class Denominator
{
private:
	unsigned long            _money;
	std::vector<int>         _denominations;
	std::vector<Combination> _combinations;
	void backTrack(int sum, Combination& combo, int it);
public:
	//
	// Default constructor
	Denominator();
	//
	//
	//void setDenominations(std::vector<int>   denominations);
	//
	//
	std::vector<Combination> getCombinations();
	//
	//
	void calculateCombinations(int amount, std::vector<int>   denominations);
	//
	// Destructor
	~Denominator();
};

