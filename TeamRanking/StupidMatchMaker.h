#pragma once
class StupidMatchMaker : public IMatchMaker
{
public:
	StupidMatchMaker();
	~StupidMatchMaker();
	void CreateMatches(Census& census, Round& round);
};

