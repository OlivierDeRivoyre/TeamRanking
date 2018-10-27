#include "stdafx.h"
#include "StupidRankEstimer.h"


StupidRankEstimer::StupidRankEstimer()
{
}


StupidRankEstimer::~StupidRankEstimer()
{
}

void StupidRankEstimer::adjustEstimatedRanks(Game& game, bool team1Win) {
	Team& winingTeam = team1Win ? game.getTeam1() : game.getTeam2();
	Team& losingTeam = team1Win ? game.getTeam2() : game.getTeam1();
	
	for(unsigned int i = 0; i < Team::TeamSize; i++)
	{
		winingTeam.getPlayer(i).getEstimatedRank().increment(1);
	}
	for (unsigned int i = 0; i < Team::TeamSize; i++)
	{
		losingTeam.getPlayer(i).getEstimatedRank().increment(-1);
	}
}
