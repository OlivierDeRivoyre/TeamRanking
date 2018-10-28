#pragma once
#include <numeric>
class Team
{

public:
	const static int TeamSize = 5;
	
	Team();
	~Team();
	void add(Player* player);
	Player& getPlayer(int i) { return *_players[i]; }
	int playGameAgainst(Team& team);

	float getEstimatedScore()
	{
		return accumulate(_players.begin(), _players.end(), 0.0f, [](float cumul, Player* player)
		{
			return cumul + player->getEstimatedSkillLevel().getScore();
		});
	}

private:
	vector<Player*> _players;
};

