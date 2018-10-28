#pragma once
class WeightedSkillEstimater : public ISkillEstimater
{
public:
	WeightedSkillEstimater();
	~WeightedSkillEstimater();
	void adjustEstimatedSkillLevels(Game& game, bool team1Win) override;
};

