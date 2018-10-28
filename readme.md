# Player level in a team game

NOV18: Work in progress

Imagine a game server (a MOBA) that have a population of players. Players play in team versus team.
Players wants to play with people of the same skill level of them.

I'm looking on how fast a player levels of a population of players can be determined when:
 - the players play in a team of 5 players.
 - a game is a match between two teams.
 - the output of the game is only a win or a loss.
 - the player skill level does not change. The player does not progress.
 - the skill player is a random number between 0 and 1000 in a normal distribution (result of 10 dices of 100). 
 - each player have a fixed skill level. The team wich has the bigger sum of score (=the better players) win. 
 - multiple games (i.e. match) can be played on one round, but a team can play only one game per round against another team.
 - A certain number of round is set (20 for example)
 - As server we compose the games and teams of each round. From the game result (win or lose) we can adjust the estimated score of each players of the game.
 
We want to found an estimated score to the players that allow to predict if a player is better than another.
We compute the accuracy of the estimation by comparing our estimate of player A has a better level than player B against the real skill. The estimate is given in percentage of good result.

Two types of strategies are tested:
 - MatchMaker: How do we choose which players go in which teams against which team for a game?
 - SkillLevelEstimer: How do we change the estimated skill of the player after a game?

 
# Random Match Maker 

Randomly pick players to create a team.

# SkillLevelEstimer: Basic Win Count
Add 1 to the estimated skill level of the player when its team win the game.
Remove 1 when losing.

# First results

After 20 rounds of Random Match Maker with Basic Rank Increment, we have 77% accuracy.

~~~
Random+WinCount nbPlayers: 50   nbRounds: 20    accuracy: 79%   standardDeviation: 2.2
Random+WinCount nbPlayers: 100  nbRounds: 20    accuracy: 79%   standardDeviation: 1.6
Random+WinCount nbPlayers: 200  nbRounds: 20    accuracy: 78%   standardDeviation: 1.6
Random+WinCount nbPlayers: 400  nbRounds: 20    accuracy: 77%   standardDeviation: 1.4
Random+WinCount nbPlayers: 1000 nbRounds: 20    accuracy: 78%   standardDeviation: 1.3
~~~
At 20 rounds, the accuracy seem to be the same whatever the number of players are.


~~~
Test influence of round count with Random+WinCount
Random+WinCount nbPlayers: 100  nbRounds: 1     accuracy: 58%   standardDeviation: 2.0
Random+WinCount nbPlayers: 100  nbRounds: 2     accuracy: 61%   standardDeviation: 2.3
Random+WinCount nbPlayers: 100  nbRounds: 5     accuracy: 67%   standardDeviation: 2.7
Random+WinCount nbPlayers: 100  nbRounds: 10    accuracy: 71%   standardDeviation: 2.2
Random+WinCount nbPlayers: 100  nbRounds: 15    accuracy: 75%   standardDeviation: 2.2
Random+WinCount nbPlayers: 100  nbRounds: 25    accuracy: 80%   standardDeviation: 1.9
Random+WinCount nbPlayers: 100  nbRounds: 50    accuracy: 84%   standardDeviation: 1.1
Random+WinCount nbPlayers: 100  nbRounds: 75    accuracy: 87%   standardDeviation: 1.5
Random+WinCount nbPlayers: 100  nbRounds: 100   accuracy: 89%   standardDeviation: 0.8
Random+WinCount nbPlayers: 100  nbRounds: 150   accuracy: 91%   standardDeviation: 1.2
Random+WinCount nbPlayers: 100  nbRounds: 200   accuracy: 92%   standardDeviation: 0.8
Random+WinCount nbPlayers: 100  nbRounds: 300   accuracy: 93%   standardDeviation: 0.7
Random+WinCount nbPlayers: 100  nbRounds: 500   accuracy: 95%   standardDeviation: 0.8
Random+WinCount nbPlayers: 100  nbRounds: 900   accuracy: 96%   standardDeviation: 0.7
~~~
The algo is slow to converge to good results. After a few rounds, we should add some intelligence to how we choose players.

# Skill based match maker

Instead of randomly picking players, we create games with players of the same estimated level. 
The algorithm is to take the 10 worst players for the first game, then take the 10 worst players after them, and so on until 
taking the best players.
To do two balanced teams with 10 players, we take the 2 worst players and randomly set one in each team. It is not the best
way to do it, it is a greedy heuristic to this bin packing problem.

With this method we improve to have an accuracy of 91% at 50 rounds, instead of 84% previously with a random match making.
~~~
Test influence of round count with SkillBased-WinCount
SkillBased-WinCount     nbPlayers: 100  nbRounds: 1     accuracy: 58%   standardDeviation: 2.6
SkillBased-WinCount     nbPlayers: 100  nbRounds: 2     accuracy: 62%   standardDeviation: 2.4
SkillBased-WinCount     nbPlayers: 100  nbRounds: 5     accuracy: 67%   standardDeviation: 2.3
SkillBased-WinCount     nbPlayers: 100  nbRounds: 10    accuracy: 74%   standardDeviation: 2.6
SkillBased-WinCount     nbPlayers: 100  nbRounds: 15    accuracy: 79%   standardDeviation: 1.6
SkillBased-WinCount     nbPlayers: 100  nbRounds: 25    accuracy: 85%   standardDeviation: 2.0
SkillBased-WinCount     nbPlayers: 100  nbRounds: 50    accuracy: 91%   standardDeviation: 1.1
SkillBased-WinCount     nbPlayers: 100  nbRounds: 75    accuracy: 92%   standardDeviation: 0.9
SkillBased-WinCount     nbPlayers: 100  nbRounds: 100   accuracy: 94%   standardDeviation: 0.8
SkillBased-WinCount     nbPlayers: 100  nbRounds: 150   accuracy: 95%   standardDeviation: 0.7
SkillBased-WinCount     nbPlayers: 100  nbRounds: 200   accuracy: 95%   standardDeviation: 0.8
SkillBased-WinCount     nbPlayers: 100  nbRounds: 300   accuracy: 96%   standardDeviation: 0.7
SkillBased-WinCount     nbPlayers: 100  nbRounds: 500   accuracy: 97%   standardDeviation: 0.7
SkillBased-WinCount     nbPlayers: 100  nbRounds: 900   accuracy: 97%   standardDeviation: 0.7
~~~

# Weighted skill estimater

Instead of giving or taking one point on a win or a loss, at the end of the game we adjust the number of points exchanged.
If team A has a total estimated score of 20 and team B as a total estimated score of 39:
 - if team A win, 2 points will be exchanged, thus team A will now be estimated as 30 while team B will be estimated at 29
 - if team B win, only few points will be exchanged (as 0.05) to reinforce the current rank.

While it seem nice, this method do not really improve the previous results, we stay at 91% at 50th round:
~~~
Test influence of round count with SkillBased-Weighted
SkillBased-Weighted     nbPlayers: 100  nbRounds: 1     accuracy: 58%   standardDeviation: 2.4
SkillBased-Weighted     nbPlayers: 100  nbRounds: 2     accuracy: 61%   standardDeviation: 2.3
SkillBased-Weighted     nbPlayers: 100  nbRounds: 5     accuracy: 68%   standardDeviation: 2.6
SkillBased-Weighted     nbPlayers: 100  nbRounds: 10    accuracy: 76%   standardDeviation: 1.6
SkillBased-Weighted     nbPlayers: 100  nbRounds: 15    accuracy: 80%   standardDeviation: 2.0
SkillBased-Weighted     nbPlayers: 100  nbRounds: 25    accuracy: 85%   standardDeviation: 1.3
SkillBased-Weighted     nbPlayers: 100  nbRounds: 50    accuracy: 91%   standardDeviation: 1.0
SkillBased-Weighted     nbPlayers: 100  nbRounds: 75    accuracy: 93%   standardDeviation: 1.1
SkillBased-Weighted     nbPlayers: 100  nbRounds: 100   accuracy: 94%   standardDeviation: 0.6
SkillBased-Weighted     nbPlayers: 100  nbRounds: 150   accuracy: 95%   standardDeviation: 0.8
SkillBased-Weighted     nbPlayers: 100  nbRounds: 200   accuracy: 96%   standardDeviation: 0.7
SkillBased-Weighted     nbPlayers: 100  nbRounds: 300   accuracy: 97%   standardDeviation: 0.6
SkillBased-Weighted     nbPlayers: 100  nbRounds: 500   accuracy: 98%   standardDeviation: 0.6
SkillBased-Weighted     nbPlayers: 100  nbRounds: 900   accuracy: 98%   standardDeviation: 0.4
~~~

If we use the Weighted skill estimater with a random team maker, it's nonetheless better than a win count estimater. 
50th round at 87% instead of 84% with winCount (and 91% with good team making).
~~~
Test influence of round count with Random-Weighted
Random-Weighted nbPlayers: 100  nbRounds: 1     accuracy: 57%   standardDeviation: 2.1
Random-Weighted nbPlayers: 100  nbRounds: 2     accuracy: 61%   standardDeviation: 2.7
Random-Weighted nbPlayers: 100  nbRounds: 5     accuracy: 68%   standardDeviation: 2.2
Random-Weighted nbPlayers: 100  nbRounds: 10    accuracy: 73%   standardDeviation: 3.0
Random-Weighted nbPlayers: 100  nbRounds: 15    accuracy: 76%   standardDeviation: 2.1
Random-Weighted nbPlayers: 100  nbRounds: 25    accuracy: 82%   standardDeviation: 1.7
Random-Weighted nbPlayers: 100  nbRounds: 50    accuracy: 87%   standardDeviation: 1.5
Random-Weighted nbPlayers: 100  nbRounds: 75    accuracy: 90%   standardDeviation: 1.0
Random-Weighted nbPlayers: 100  nbRounds: 100   accuracy: 91%   standardDeviation: 1.0
Random-Weighted nbPlayers: 100  nbRounds: 150   accuracy: 93%   standardDeviation: 1.1
Random-Weighted nbPlayers: 100  nbRounds: 200   accuracy: 94%   standardDeviation: 1.1
Random-Weighted nbPlayers: 100  nbRounds: 300   accuracy: 95%   standardDeviation: 0.8
Random-Weighted nbPlayers: 100  nbRounds: 500   accuracy: 97%   standardDeviation: 0.6
Random-Weighted nbPlayers: 100  nbRounds: 900   accuracy: 98%   standardDeviation: 0.6
~~~

