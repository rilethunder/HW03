/*
* This class is where the functions of the program are coded
*
*
*
*/
#include <iostream>
#include <string>
#include "Game.h"

using namespace std;

/*
* This class is for storing player names and their turn value, used as boolean
* @method setName sets the name, @ param &gname as the given name
* @method setTurn sets the turn value, with @param &t as the given turn value
* @method init is the initialization method, using both earlier parameters
* @var name is the name of player
* @var turn is the turn value of player
*/
class player
{
public:

	void setName( string &gname )
	{
		name = gname;
	}
	void setTurn(int t)
	{
		turn = t;
	}
	void init(int t, string &gname)
	{
		name = gname;
		turn = t;
	}
	
	string name;
	int turn;
};

/*
* Determines whose turn it will be, and returns that player
*@ param player &a , player &b the players to be compared, using references
*
*/
player turn(player &a, player &b)
{
	if(a.turn == 1) 
	{
		a.setTurn(0);
		b.setTurn(1);
		return a;
	}
	else if(b.turn ==1)
	{
		a.setTurn(1);
		b.setTurn(0);
		return b;
	}
}

/*
* Returns an integer based from the position given
* It also draws the field in its initial state, depending on the number of rows given in the input
* It will be called time and time again , with the change of the position of the token, until either player wins
* @ parameter &a refers to the address of the given int
* @ parameter pos refers to the position of the token
*/
int makeField(int &a, int pos)
{
	for (int i =1; i < a + 1; ++i)
	{
		cout << "+-";
	}
	cout << "+\n";
	for (int i =1; i < a + 1; ++i)
	{
		if(i == pos) cout << "|@";
		else cout << "| ";
	}
	cout << "|\n";
	for (int i =1; i < a + 1; ++i)
	{
		cout << "+-";
	}
	cout << "+\n";
	
	cout << "Pos: " <<	+ pos << "\n";
	return pos;
}

/*
* This function checks for any rebounds, and recalculates them to accommodate said rebound, and also redraws the field
* @ param &pos refers to the position given, normally with the player increment input added
* @ param &fields refers to the number of cells for the given round, input by the player
* @ param inc refers to the increment given by players
* Has a call function of makeField
*/

int move(int pos, int &fields, int inc)
{
	int newinc = inc;
	int end = 0;
	int start = 0;
	if((pos + inc) > fields)
	{
		newinc = newinc - (fields - pos);
		end = 1;
		while(pos + newinc > fields)
		{
			if(pos + newinc <= fields && pos + newinc >= 1)
			{
				return makeField(fields, pos + newinc);
			}
			if(end)
			{
				newinc = newinc - (fields -1);
				start = 1;
				end = 0;
			}
			else if(start)
			{
				newinc = newinc - (fields- 1);
				end = 1;
				start = 0;
			}
		}
		if(pos + newinc <= fields && pos + newinc >= 1)
		{
				return makeField(fields, pos + newinc);
		}
	}
	else
	{
		return makeField(fields, pos+inc);
	}	
}
/*
* The is the "main" method, where the sequence of the game will be coded
* This is also where all inputs will be processed
* @var fields is the cells to be given by the user for the round
* @var rang1, rang2 is the range of movement given by the player
* @var inc is the increment/movement provided by either player
* @var p1, p2 is the given player names of players
*/
int start()
{
	int fields, inc, rang1, rang2, newpos, goal;
	string p1, p2;
	player now;
	cin >> fields;
	cin >> rang1;
	cin >>rang2;
	p1 = "a";
	p2 = "b";
	player a, b;
	a.init(1, p1);
	b.init(0, p2);
	int pos = makeField(fields, 1); //initialization, 1 is the starting point
	while (pos != fields)
	{
		now = turn(a, b);
		cout << now.name << "'s turn: ";
		cin >> inc;
		if(inc < rang1 || inc > rang2) //checks if input is within range
		{
			while(inc < rang1 || inc > rang2) //allows the player to reenter a value until within range
			{
				cout << "Input not in range! \n";
				cout << now.name <<"'s turn: ";
				cin >> inc;
			}
		}
		pos = move(pos, fields, inc);
	}
	if(pos == fields) // fields - 1, given on how array-counting works
	{
		cout << now.name << " wins!";
	}
	return 0;
}

