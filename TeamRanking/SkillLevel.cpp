#include "stdafx.h"
#include "SkillLevel.h"


static int getNormalDistributionRandomScore() {
	int score = 0;
	for (int i = 0; i < 10; i++) 
	{
		score += rand() % 101;
	}
	return score;
}

SkillLevel::SkillLevel()
{
	_score = getNormalDistributionRandomScore();
}


SkillLevel::~SkillLevel()
{
}
