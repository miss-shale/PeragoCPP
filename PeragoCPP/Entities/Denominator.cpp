#include "Denominator.h"

//
//
Denominator::Denominator()
{
	_money = 0;

	_denominations.clear();

	_combinations.clear();
}


//
//
Denominator::~Denominator()
{
}

//
//
//void Denominator::setDenominations(std::vector<int>   denominations)
//{}
//
//
std::vector<Combination> Denominator::getCombinations()
{
	return _combinations;
}
//
//
void Denominator::backTrack(int sum, Combination& combo, int it) 
{
	if (sum == 0) {
		_combinations.push_back(combo);
		return;
	}
	while (it < _denominations.size() && sum - _denominations[it] >= 0) {
		combo.addToList(_denominations[it]);
		backTrack( sum - _denominations[it], combo, it);
		it++;
		combo.pop();
	}
}

//
//
void Denominator::calculateCombinations(int amount, std::vector<int>   denominations)
{
    // sort denominations
    std::sort(denominations.begin(), denominations.end());

    // remove duplicates
    denominations.erase(std::unique(denominations.begin(), denominations.end()), denominations.end());

	Combination _combo;
	_denominations = denominations;
	_combinations.clear();
	backTrack( amount, _combo, 0);
}