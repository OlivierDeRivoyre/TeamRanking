#pragma once
class IMatchMaker
{
public:
	IMatchMaker();
	~IMatchMaker();
	virtual void createGames(Census& census, Round& round) = 0;
};

