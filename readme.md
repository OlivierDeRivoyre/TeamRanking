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
Random+WinCount nbPlayers: 100  nbRounds: 1     accuracy: 58%   standardDeviation: 2.2
Random+WinCount nbPlayers: 100  nbRounds: 2     accuracy: 62%   standardDeviation: 1.6
Random+WinCount nbPlayers: 100  nbRounds: 5     accuracy: 67%   standardDeviation: 2.8
Random+WinCount nbPlayers: 100  nbRounds: 10    accuracy: 73%   standardDeviation: 1.5
Random+WinCount nbPlayers: 100  nbRounds: 15    accuracy: 76%   standardDeviation: 2.2
Random+WinCount nbPlayers: 100  nbRounds: 25    accuracy: 79%   standardDeviation: 1.8
Random+WinCount nbPlayers: 100  nbRounds: 50    accuracy: 85%   standardDeviation: 1.6
Random+WinCount nbPlayers: 100  nbRounds: 100   accuracy: 88%   standardDeviation: 1.7
Random+WinCount nbPlayers: 100  nbRounds: 200   accuracy: 92%   standardDeviation: 1.1
Random+WinCount nbPlayers: 100  nbRounds: 400   accuracy: 94%   standardDeviation: 0.8
~~~
The algo is slow to converge to good results. After a few rounds, we should add some intelligence to how we choose players.