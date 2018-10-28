#include "stdafx.h"
#include "ISkillEstimater.h"


ISkillEstimater::ISkillEstimater()
{
}


ISkillEstimater::~ISkillEstimater()
{
}
void ISkillEstimater::adjustEstimatedSkillLevels(Round& round) 
{
	for (unsigned int i = 0; i < round.gamesCount(); i++) 
	{
		Game& game = round.getGame(i);
		bool team1Win = game.run();
		this->adjustEstimatedSkillLevels(game, team1Win);
	}
}