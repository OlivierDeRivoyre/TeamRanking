#include "stdafx.h"
#include "Team.h"


Team::Team()
{
	_players.reserve(Team::TeamSize);
}


Team::~Team()
{
}

void Team::add(Player* player) {
	_ASSERT(player != nullptr);
	_players.push_back(player);
}

int Team::playGameAgainst(Team& team) {
	int teamScore = 0;
	for (unsigned int i = 0; i < _players.size(); i++)
	{
		teamScore += _players[i]->playGame();
	}
	return teamScore;
}