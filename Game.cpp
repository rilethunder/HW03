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
	for (int i =0; i < a; i++)
	{
		cout << "+-";
	}
	cout << "+\n";
	for (int i =0; i < a; i++)
	{
		if(i == pos) cout << "|@";
		else cout << "| ";
	}
	cout << "|\n";
	for (int i =0; i < a; i++)
	{
		cout << "+-";
	}
	cout << "+\n";
	return pos;
}

/*
* This function checks for any rebounds, and recalculates them to accommodate said rebound, and also redraws the field
* @ param &pos refers to the position given, normally with the player increment input added
* @ param &fields refers to the number of cells for the given round, input by the player
* Has a call function of makeField
*/

int move(int &pos, int &fields)
{
	if(pos >= fields)
		{
			if ((pos - fields) >= fields) return 0; // if the difference of the position and the max number of cells, then the token goes back to start
			else
			{
				pos = fields - (pos - fields); //otherwise, rebound
			}
		}
		return makeField(fields, pos);
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
	int fields, inc, rang1, rang2, newpos;
	string p1, p2;
	player now;
	cout << "Enter the number of cells for this round: ";
	cin >> fields;
	cout << "Enter the allowable movement range for the game;Minimum, followed by maximum: ";
	cin >> rang1;
	cin >>rang2;
	cout << "Name for Player 1: ";
	cin >> p1;
	cout << "Name for Player 2: ";
	cin >> p2;
	player a, b;
	a.init(1, p1);
	b.init(0, p2);
	int pos = makeField(fields, 0); //initialization, 0 is the starting point
	while (pos != fields - 1)
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
		newpos = pos + inc;
		pos = move(newpos, fields);
	}
	if(pos == fields - 1) // fields - 1, given on how array-counting works
	{
		cout << now.name << " wins!";
	}
	return 0;
}

