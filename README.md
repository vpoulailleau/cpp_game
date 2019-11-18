# cpp_game

Toy project to discover C++

## Presentation

We will create a game that mixes strategy and chance. If you want to create a variant of this game, it is possible.

It is a 1 player vs 1 game.

Each player receives an identical amount of money randomly chosen. This money makes it possible to creat a team by recruiting characters.

These characters will fight each other until a team disappears and is defeated.

## Characters

A character has:

* a cost
* life points
* a scream (screamed during a fight)
* a strike force
* an ability to strike
* you may consider adding special powers in a second step

## A fight

In each round, one character from each team is randomly selected. These two characters are engaged in a fight.

Each character rolls a 6-sided die and makes his war scream. If the die has a value less than or equal to the character's skill, then "strike force" health points are removed from the opponent.

A character with no life points dies.

## Types of characters

### Archer

* Cost: 200
* Health points: 50
* Scream: It's up to you
* Striking force: 5
* Skill: 3

### Farmer

* Cost: 50
* Health points: 20
* Scream: It's up to you
* Striking force: 1
* Skill: 1

### Knight

* Cost: 300
* Health points: 60
* Scream: It's up to you
* Striking force: 3
* Skill: 4

### Giant

* Cost: 500
* Health points: 20
* Scream: It's up to you
* Striking force: 4
* Skill: 5

### Kamikaze

* Cost: 50
* Health points: 10
* Scream: It's up to you
* Striking force: 4
* Skill: 6

## Organizational possibilities

* Creation of a main.cpp
* Display of the game title
* Creating the Archer class
* Archer instanciation
* Fight between archers
* Management of team creation
* Adding new character types (need for C++ inheritance)
* Great world competition on your game
* And for the more advanced:
  * Graphical interface
  * Network play
  * …
