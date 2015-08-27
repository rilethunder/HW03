HW03 — TextGame (deadline: 2015-09-03)
===

Write a 2-player text-based token skipping game.

Mechanics
====

* The board has is one-dimension `n` cells. So a 10-board looks like this:
```
  +-+-+-+-+-+-+-+-+-+-+
  |@| | | | | | | | | |
  +-+-+-+-+-+-+-+-+-+-+
```
* A token, marked by `@`, starts at cell `0`. 
* The two players take turns moving the tokens `a` to `b` cells forward.
* First player to reach the end wins.
* If the player gets out of bounds, the token "bounces" back with the leftover steps. For example, if board state is at:
```
  +-+-+-+-+-+-+-+-+-+-+
  | | | | | | | |@| | |
  +-+-+-+-+-+-+-+-+-+-+
```
and the player moves by 3 spaces, the token will end up as
```
  +-+-+-+-+-+-+-+-+-+-+
  | | | | | | | | |@| |
  +-+-+-+-+-+-+-+-+-+-+
```

Example
====
Let `n=10`, `a=1`, and `b=4`. So we have a board with *10* cells and players can move the token by *1* to *4* spaces:
```
10 1 4
  +-+-+-+-+-+-+-+-+-+-+
  |@| | | | | | | | | |
  +-+-+-+-+-+-+-+-+-+-+
a>
```
Player A inputs `1`:
```
  +-+-+-+-+-+-+-+-+-+-+
  | |@| | | | | | | | |
  +-+-+-+-+-+-+-+-+-+-+
b>
```

Player B inputs `4`:
```
  +-+-+-+-+-+-+-+-+-+-+
  | | | | | |@| | | | |
  +-+-+-+-+-+-+-+-+-+-+
a> 
```

Player A inputs 4:
```
  +-+-+-+-+-+-+-+-+-+-+
  | | | | | | | | | |@|
  +-+-+-+-+-+-+-+-+-+-+
A wins!
```

Advanced Mechanics
===
A cell board can have random values like this:

```
  +---+---+---+---+---+---+---+---+---+---+
  | @ | 1 |   |   |-2 |   |   | 1 |   |   |
  +---+---+---+---+---+---+---+---+---+---+
```
(You should generate them such that the token won't do "chain jumping")  
If the token lands on a slot with a number, it will jump by that much. For example, if player A entered `4`, the token ends up at
```
  +---+---+---+---+---+---+---+---+---+---+
  |   | 1 | @ |   |-2 |   |   | 1 |   |   |
  +---+---+---+---+---+---+---+---+---+---+
```
