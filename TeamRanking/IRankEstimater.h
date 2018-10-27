#pragma once
class IRankEstimater
{
public:
	IRankEstimater();
	~IRankEstimater();
	virtual void adjustEstimatedRanks(Game& game, bool team1Win) = 0;

	void adjustEstimatedRanks(Round& round);
};

