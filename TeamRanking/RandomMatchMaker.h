#pragma once
class RandomMatchMaker : public IMatchMaker
{
public:
	RandomMatchMaker();
	~RandomMatchMaker();
	void createGames(Census& census, Round& round) override;
};

