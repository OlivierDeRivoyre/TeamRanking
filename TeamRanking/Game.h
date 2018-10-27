#pragma once
class Game
{
public:
	const static int GameSize = 2 * Team::TeamSize;

	Game(Team team1, Team team2);
	~Game();	
	Team& getTeam1() { return _team1; }
	Team& getTeam2() { return _team2; }
	bool run();
private:
	Team _team1;
	Team _team2;
};

