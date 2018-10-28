#include "stdafx.h"
#include "EstimationChecker.h"


EstimationChecker::EstimationChecker()
{
}


EstimationChecker::~EstimationChecker()
{
}

float EstimationChecker::computePronostic(Census& census)
{
	int totalComparison = 0;
	int correctCount = 0;
	for (int i = 0; i < census.getPlayerCount(); i++) 
	{
		Player& p1 = census.getPlayer(i);
		for (int j = i + 1; j < census.getPlayerCount(); j++) 
		{
			Player& p2 = census.getPlayer(j);
			bool estimateP1Wins = p1.getEstimatedSkillLevel().getScore() >= p2.getEstimatedSkillLevel().getScore();
			bool p1Wins = p1.playGame() >= p2.playGame();
			totalComparison++;
			if(estimateP1Wins == p1Wins)
			{
				correctCount++;
			}			
		}
	}
	return round(((float)correctCount * 100) / totalComparison);
}