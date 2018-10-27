# Player level in a team game

NOV18: Work in progress

Imagine a game server (a MOBA) that have a population of players. Players play in team versus team.
Players wants to play with people of the same level of them.

I'm looking on how fast a player levels of a population of players can be determined when:
 - the players play in a team of 5 players.
 - a game is a match between two teams.
 - the output of the game is only a win or a loss.
 - the player level does not change. The player does not progress.
 - each player has a real score (skill level). The team wich has the bigger sum of score (=the better players) win. 
 - multiple games (i.e. match) can be played on one round, but a team can play only one game per round against another team.
 - A certain number of round is set (20 for example)
 - As server we compose the games and teams of each round. From the game result (win or lose) we can adjust the estimated score of each players of the game.
 
We want to found an estimated score to the players that allow to predict if a player is better than another.
We compute the accuracy of the estimation by comparing our estimate of player A has a better level than player B against the real skill. The estimate is given in percentage of good result.

Two types of strategies are tested:
 - MatchMaker: How do we choose which players go in which teams against which team for a game?
 - RankEstimer: How do we change the estimated score of the player after a game?

 
# Random Match Maker 

Randomly pick player to create a team.

# Basic rank increment/decrement
Add 1 to the score when winning
Remove 1 when losing.


After 20 rounds of Random Match Maker with Basic Rank Increment, we have 77% accuracy.
