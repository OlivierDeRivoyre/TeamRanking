#include "stdafx.h"
#include "EstimationChecker.h"


EstimationChecker::EstimationChecker()
{
}


EstimationChecker::~EstimationChecker()
{
}

float EstimationChecker::computeAccuracy(Census& census)
{
	int totalComparison = 0;
	int correctCount = 0;
	for (int sample = 0; sample < 1000; sample++)
	{
		int i = rand() % census.getPlayerCount();
		int j = rand() % census.getPlayerCount();
		Player& p1 = census.getPlayer(i);
		Player& p2 = census.getPlayer(j);
		bool estimateP1Wins = p1.getEstimatedSkillLevel().getScore() >= p2.getEstimatedSkillLevel().getScore();
		bool p1Wins = p1.playGame() >= p2.playGame();
		totalComparison++;
		if (estimateP1Wins == p1Wins)
		{
			correctCount++;
		}
	}
	return ((float)correctCount) / totalComparison;
}