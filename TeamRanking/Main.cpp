// TeamRanking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void EvaluateAlgos(IMatchMaker& matchMaker, IRankEstimater& rankEstimer) 
{
	Census census = Census(100);
	for (unsigned int i = 0; i < 20; i++) 
	{
		Round round = Round(&census, i);
		matchMaker.CreateMatches(census, round);		
		rankEstimer.adjustEstimatedRanks(round);
	}
	float correctness = ScoreChecker().computePronostic(census);
	cout << "Correctness: " << correctness << endl;
}

int main()
{
	std::cout << "Hello" << std::endl;	

	EvaluateAlgos(StupidMatchMaker(), StupidRankEstimer());



	std::cin.get();
    return 0;
}

