#include "stdafx.h"
#include "IRankEstimater.h"


IRankEstimater::IRankEstimater()
{
}


IRankEstimater::~IRankEstimater()
{
}
void IRankEstimater::adjustEstimatedRanks(Round& round) 
{
	for (unsigned int i = 0; i < round.gamesCount(); i++) 
	{
		Game& game = round.getGame(i);
		bool team1Win = game.run();
		this->adjustEstimatedRanks(game, team1Win);
	}
}