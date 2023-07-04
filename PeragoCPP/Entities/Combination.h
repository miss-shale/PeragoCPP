#pragma once

#include <vector>

//
// Simply stores a list of numbers to represent
// a combination of coins
class Combination
{
private:
	std::vector<int> _coins;

public:
	//
	// Default constructor
	Combination();
	//
	// 
	void addToList(int coin);
	//
	// 
	void pop();
	//
	// 
	std::vector<int> getCoinList();
	//
	// Destructor
	~Combination();
};

