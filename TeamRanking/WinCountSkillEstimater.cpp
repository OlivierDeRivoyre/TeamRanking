#include "stdafx.h"
#include "WinCountSkillEstimater.h"


WinCountSkillEstimater::WinCountSkillEstimater()
{
}


WinCountSkillEstimater::~WinCountSkillEstimater()
{
}

void WinCountSkillEstimater::adjustEstimatedSkillLevels(Game& game, bool team1Win) {
	Team& winingTeam = team1Win ? game.getTeam1() : game.getTeam2();
	Team& losingTeam = team1Win ? game.getTeam2() : game.getTeam1();
	
	for(unsigned int i = 0; i < Team::TeamSize; i++)
	{
		winingTeam.getPlayer(i).getEstimatedSkillLevel().increment(1);
	}
	for (unsigned int i = 0; i < Team::TeamSize; i++)
	{
		losingTeam.getPlayer(i).getEstimatedSkillLevel().increment(-1);
	}
}
