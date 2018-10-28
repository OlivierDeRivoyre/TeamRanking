#pragma once
class EstimatedSkillLevel
{
public:
	EstimatedSkillLevel();
	~EstimatedSkillLevel();
	void increment(float incr) { _score += incr; }
	float getScore() { return _score; }
private:
	float _score = 500;
};

