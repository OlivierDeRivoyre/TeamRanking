#pragma once
class EstimatedSkillLevel
{
public:
	EstimatedSkillLevel();
	~EstimatedSkillLevel();
	void increment(int incr) { _score += incr; }
	int getScore() { return _score; }
private:
	int _score = 500;
};

