#include "stdafx.h"
#include <iomanip>


float getAverage(vector<float> list)
{
	float total = 0;
	for (size_t i = 0; i < list.size(); i++) 
	{
		total += list[i];
	}
	return total / list.size();
}

float getStandardDeviation(vector<float> list, float average)
{
	float total = 0;
	for (size_t i = 0; i < list.size(); i++)
	{
		total += pow(list[i] - average, 2);
	}
	return sqrt(total / list.size());
}

void evaluateAlgos(char configName[], IMatchMaker& matchMaker, ISkillEstimater& rankEstimer, int playersCount, int roundCount) 
{
	vector<float> accuracyResults;
	for (int test = 0; test < 20; test++)
	{
		Census census = Census(playersCount);
		for (unsigned int i = 0; i < roundCount; i++)
		{
			Round round = Round(&census, i);
			matchMaker.createGames(census, round);
			rankEstimer.adjustEstimatedSkillLevels(round);
		}
		float accuracy = EstimationChecker().computeAccuracy(census)*100;
		accuracyResults.push_back(accuracy);
	}
	float average = getAverage(accuracyResults);
	float standardDeviation = getStandardDeviation(accuracyResults, average);
	
	cout << fixed;
	cout << configName 
		<< "\tnbPlayers: " << playersCount
		<< "\tnbRounds: " << roundCount 
		<< "\taccuracy: " << setprecision(0) << average
		<< "%\tstandardDeviation: " << setprecision(1) << standardDeviation
		<< endl;
}

void testSizesInfluence(char configName[], IMatchMaker& matchMaker, ISkillEstimater& rankEstimer) 
{
	

	cout << "Test influence of round count with " << configName << endl;
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 1);
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 2);
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 5);
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 10);
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 15);
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 25);
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 50);
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 100);
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 200);
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 400);
	
	cout << "Test influence of players count with " << configName << endl;
	evaluateAlgos(configName, matchMaker, rankEstimer, 50, 20);
	evaluateAlgos(configName, matchMaker, rankEstimer, 100, 20);
	evaluateAlgos(configName, matchMaker, rankEstimer, 200, 20);
	evaluateAlgos(configName, matchMaker, rankEstimer, 400, 20);
	evaluateAlgos(configName, matchMaker, rankEstimer, 1000, 20);	
}

int main()
{
	srand((unsigned int) time(NULL));
	
	testSizesInfluence("Random+WinCount", RandomMatchMaker(), WinCountSkillEstimater());
	

	cout << "Press enter to exit..." << endl;
	cin.get();
    return 0;
}

