#pragma once
class Round
{
public:
	Round(Census *census, int roundNumber);
	~Round();
	void add(Game game);
	size_t gamesCount() { return _games.size(); }
	Game& getGame(int i) { return _games[i]; }
private:
	Census* _census;
	int _roundNumber;
	vector<Game> _games;
};

