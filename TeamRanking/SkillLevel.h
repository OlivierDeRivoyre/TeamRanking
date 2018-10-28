#pragma once
class SkillLevel
{
public:
	SkillLevel();
	~SkillLevel();
	int getScore() { return _score; }
private:
	int _score;
};

