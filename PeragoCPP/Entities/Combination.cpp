#include "Combination.h"

//
//
Combination::Combination()
{
	_coins.clear();
}


//
//
Combination::~Combination()
{
	//TODO: Implement if necessary
}
//
// 
void Combination::pop()
{
	_coins.pop_back();
}
//
// 
void Combination::addToList(int coin)
{
	_coins.push_back(coin);
}
//
// 
std::vector<int> Combination::getCoinList()
{
	return _coins;
}