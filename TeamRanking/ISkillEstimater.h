#pragma once
class ISkillEstimater
{
public:
	ISkillEstimater();
	~ISkillEstimater();
	virtual void adjustEstimatedSkillLevels(Game& game, bool team1Win) = 0;

	void adjustEstimatedSkillLevels(Round& round);
};

