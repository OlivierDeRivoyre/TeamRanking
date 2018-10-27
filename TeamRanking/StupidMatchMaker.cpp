#include "stdafx.h"
#include "StupidMatchMaker.h"


StupidMatchMaker::StupidMatchMaker()
{
}


StupidMatchMaker::~StupidMatchMaker()
{
}

void StupidMatchMaker::CreateMatches(Census& census, Round& round) {
	vector<Player*> players = census.getAllPlayers();
	// Mix players
	for (unsigned int i = 0; i < players.size(); i++)
	{
		int swapIndex = rand() % players.size();
		auto old = players[i];
		players[i] = players[swapIndex];
		players[swapIndex] = old;
	}
	// Create games with two teams
	for (unsigned int gameNumber = 0; gameNumber * Game::GameSize < players.size(); gameNumber++) 
	{
		Team team1;
		for (unsigned int i = 0; i < Team::TeamSize; i++)
		{
			team1.add(players[gameNumber * Game::GameSize + i]);
		}
		Team team2;
		for (unsigned int i = 0; i < Team::TeamSize; i++)
		{
			team2.add(players[gameNumber * Game::GameSize + Team::TeamSize + i]);
		}
		round.add(Game(team1, team2));
	}
		
}
