#include "stdafx.h"
#include <iomanip>

void evaluateAlgos(IMatchMaker& matchMaker, ISkillEstimater& rankEstimer) 
{
	Census census = Census(100);
	for (unsigned int i = 0; i < 20; i++) 
	{
		Round round = Round(&census, i);
		matchMaker.createGames(census, round);		
		rankEstimer.adjustEstimatedSkillLevels(round);
	}
	float correctness = ScoreChecker().computePronostic(census);
	cout << "Correctness: " << correctness << endl;
}

int main()
{
	srand((unsigned int) std::time(NULL));
	std::cout << "Hello" << std::endl;	

	evaluateAlgos(RandomMatchMaker(), WinCountSkillEstimater());



	std::cin.get();
    return 0;
}

