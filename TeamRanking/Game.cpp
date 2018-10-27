#include "stdafx.h"
#include "Game.h"


Game::Game(Team team1, Team team2)
{
	_team1 = team1;
	_team2 = team2;
}


Game::~Game()
{
}

bool Game::run() {
	int team1Score = _team1.playGameAgainst(_team2);
	int team2Score = _team2.playGameAgainst(_team1);
	return team1Score >= team2Score;
}