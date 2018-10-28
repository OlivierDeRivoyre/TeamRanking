#pragma once

class Player
{
public:
	Player(int id);
	~Player();
	EstimatedSkillLevel& getEstimatedSkillLevel() { return _estimatedSkillLevel; }
	int playGame();
private:
	int _id;
	SkillLevel _rank;
	EstimatedSkillLevel _estimatedSkillLevel;
};

