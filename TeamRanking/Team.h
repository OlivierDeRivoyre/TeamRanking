#pragma once
class Team
{

public:
	const static int TeamSize = 5;
	
	Team();
	~Team();
	void add(Player* player);
	Player& getPlayer(int i) { return *_players[i]; }
	int playGameAgainst(Team& team);
private:
	vector<Player*> _players;
};

