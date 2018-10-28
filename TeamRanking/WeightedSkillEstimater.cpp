#include "stdafx.h"
#include "WeightedSkillEstimater.h"


WeightedSkillEstimater::WeightedSkillEstimater()
{
}


WeightedSkillEstimater::~WeightedSkillEstimater()
{
}


void WeightedSkillEstimater::adjustEstimatedSkillLevels(Game& game, bool team1Win) {
	Team& winingTeam = team1Win ? game.getTeam1() : game.getTeam2();
	Team& losingTeam = team1Win ? game.getTeam2() : game.getTeam1();
	float winingEstimatedTeamScore = winingTeam.getEstimatedScore();
	float losingEstimatedTeamScore = losingTeam.getEstimatedScore();

	// we expect: winScore > losingScore
	float adjust = (1 + losingEstimatedTeamScore - winingEstimatedTeamScore) / Game::GameSize;
	if (adjust <= 0.01f) 
	{
		adjust = 0.01f;
	}

	for (unsigned int i = 0; i < Team::TeamSize; i++)
	{
		winingTeam.getPlayer(i).getEstimatedSkillLevel().increment(adjust);
	}
	for (unsigned int i = 0; i < Team::TeamSize; i++)
	{
		losingTeam.getPlayer(i).getEstimatedSkillLevel().increment(-adjust);
	}
}
