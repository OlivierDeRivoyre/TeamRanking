#pragma once
class StupidRankEstimer : public IRankEstimater
{
public:
	StupidRankEstimer();
	~StupidRankEstimer();
	void adjustEstimatedRanks(Game& game, bool team1Win);
};

