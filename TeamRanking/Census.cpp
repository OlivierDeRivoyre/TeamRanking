#include "stdafx.h"
#include "Census.h"


Census::Census(int nbPlayer)
{
	for (int i = 0; i < nbPlayer; i++) {
		_players.push_back(Player(i));
	}
}


Census::~Census()
{
}

vector<Player*> Census::getAllPlayers()
{
	auto copy = vector<Player*>();
	for (unsigned int i = 0; i < _players.size(); i++)
	{
		copy.push_back(&_players[i]);
	}
	return copy;
}