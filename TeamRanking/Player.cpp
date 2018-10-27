#include "stdafx.h"
#include "Player.h"


Player::Player(int id)
{
	_id = id;
}


Player::~Player()
{
}

int Player::playGame() {
	return _rank.getScore();
}