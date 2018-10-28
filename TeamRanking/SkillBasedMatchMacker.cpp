#include "stdafx.h"
#include "SkillBasedMatchMacker.h"
#include <algorithm>

SkillBasedMatchMacker::SkillBasedMatchMacker()
{
}


SkillBasedMatchMacker::~SkillBasedMatchMacker()
{
}

void SkillBasedMatchMacker::createGames(Census& census, Round& round)
{
	vector<Player*> players = census.getAllPlayers();
	sort(players.begin(), players.end(), [](Player* p1, Player* p2)
	{
		return p1->getEstimatedSkillLevel().getScore() < p2->getEstimatedSkillLevel().getScore();
	});
	// Create games with two teams
	for (unsigned int gameNumber = 0; gameNumber * Game::GameSize < players.size(); gameNumber++)
	{
		Team team1;
		Team team2;
		for (unsigned int i = 0; i < Team::TeamSize; i++)
		{
			auto p1 = players[gameNumber * Game::GameSize + 2 * i];
			auto p2 = players[gameNumber * Game::GameSize + 2 * i + 1];
			if (rand() % 2 == 0)
			{
				team1.add(p1);
				team2.add(p2);
			}
			else
			{
				team1.add(p2);
				team2.add(p1);
			}
		}
				
		round.add(Game(team1, team2));
	}
}
