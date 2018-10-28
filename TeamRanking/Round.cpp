#include "stdafx.h"
#include "Round.h"


Round::Round(Census *census, int roundNumber)
{
	_census = census;
	_roundNumber = roundNumber;
	_games.reserve(census->getPlayerCount() / Game::GameSize);
}


Round::~Round()
{
}

void Round::add(Game game) {
	_games.push_back(game);
}