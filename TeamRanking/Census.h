#pragma once


class Census
{
public:
	Census(int nbPlayer);
	~Census();
	vector<Player*> getAllPlayers();
	size_t getPlayerCount() { return _players.size(); }
	Player& getPlayer(int i) { return _players[i]; }
private:
	vector<Player> _players;
};

