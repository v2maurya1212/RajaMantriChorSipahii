Note := This program has successfully been compiled and run using gcc compiler.

This program is based on an Indian game “Char Parchi” (Four slips).
Rules-
1. There are 4 players in this game.
2. Each player is given a status (either a King or a Lieutenant or a Soldier or a Thief) randomly.
3. The player who is given the status of King asks who the lieutenant is.
4. The player who is given the status of lieutenant tells that he is the lieutenant.
5. The lieutenant is then told to find the thief from the other two players.
6. The status of the other two players is hidden until the lieutenant makes a choice.
7. If the lieutenant guessed correctly then points will be awarded to him otherwise points will be awarded to the thief.

Scoring rules -

(a) King gets 1000 points in each round.
(b) Soldier gets 500 points in each round.
(c) Lieutenant if successfully guessed the thief gets 800 points otherwise he gets 0 points.
(d) If the lieutenant successfully guessed the thief then the thief gets 0 points otherwise the thief gets 800 points.
(e) Whoever scores 10000 points first will win.

Some cases you need to know - 

case 1: If someone has already scored 9000 points or higher and he gets the King status then he will win. Because, the moment he gets the king status he reached 10000 points (9000+1000).

case 2: If someone has already scored 9500 points or higher and after the guess by lieutenant he turned out to be the soldier then he will win because he was to get 500 points irrespective of the lieutenant's choice and hence reached 10000 points before the guess.


