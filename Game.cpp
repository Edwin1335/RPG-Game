#include "Game.h"

void Game::RemoveCharacter(int index)
{
	if (index > 2 || index < 0)
		cout << "Invalid index!" << endl;
	else
	{
		num_of_characters--;
	}
}

void Game::AddCharacter(Character* added_player)
{
	if (num_of_characters == 2)
		cout << "Character limit reached, please wait for the next game!" << endl;
	else
		players[num_of_characters] = added_player;
	num_of_characters++;
}

void Game::NextTurn()
{
	if (num_of_characters != 2)
		cout << "Need more players!" << endl;
	else
	{
		players[0]->Attack(players[1]);
		if (players[0]->getHealth() < 0)
		{
			cout << "Player one wins!" << endl;
			exit(EXIT_FAILURE);
		}

		players[1]->Attack(players[0]);
		if (players[1]->getHealth() < 0)
		{
			cout << "Player two wins!" << endl;
			exit(EXIT_FAILURE);
		}

		cout << players[0]->getName() << ": " << endl;
		players[0]->print();
		cout << endl << players[1]->getName() << ": " << endl;
		players[1]->print();
	}
}