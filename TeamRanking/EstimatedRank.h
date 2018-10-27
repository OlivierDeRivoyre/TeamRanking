#pragma once
class EstimatedRank
{
public:
	EstimatedRank();
	~EstimatedRank();
	void increment(int incr) { _score += incr; }
	int getScore() { return _score; }
private:
	int _score = 500;
};

