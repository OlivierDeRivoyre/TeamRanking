#pragma once

class Player
{
public:
	Player(int id);
	~Player();
	EstimatedRank& getEstimatedRank() { return _estimatedRank; }
	int playGame();
private:
	int _id;
	Rank _rank;
	EstimatedRank _estimatedRank;
};

