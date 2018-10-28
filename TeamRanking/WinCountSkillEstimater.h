#pragma once
class WinCountSkillEstimater : public ISkillEstimater
{
public:
	WinCountSkillEstimater();
	~WinCountSkillEstimater();
	void adjustEstimatedSkillLevels(Game& game, bool team1Win);
};

