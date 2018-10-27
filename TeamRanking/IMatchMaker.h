#pragma once
class IMatchMaker
{
public:
	IMatchMaker();
	~IMatchMaker();
	virtual void CreateMatches(Census& census, Round& round) = 0;
};

