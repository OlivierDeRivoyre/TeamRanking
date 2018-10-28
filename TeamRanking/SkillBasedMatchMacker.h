#pragma once
class SkillBasedMatchMacker : public IMatchMaker
{
public:
	SkillBasedMatchMacker();
	~SkillBasedMatchMacker();

	void createGames(Census& census, Round& round) override;
};

