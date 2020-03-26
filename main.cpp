#include "Character.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Game.h"

int main()
{
	ifstream inputFile("test.txt");

	bool end_game = false;
	char choose;
	string name, race, weapon_name, spell_name, level, health, weapon_damage, stamina, stamina_cost;
	string mana, num_of_spells, spell_damage, mana_cost, garabage;

	if (inputFile.fail())
	{
		cout << "ERROR: input fail!" << endl;
		exit(EXIT_FAILURE);
	}

		getline(inputFile, garabage);
		getline(inputFile, name);
		getline(inputFile, race);
		getline(inputFile, level);
		getline(inputFile, health);
		getline(inputFile, stamina);
		getline(inputFile, weapon_name);
		getline(inputFile, weapon_damage);
		getline(inputFile, stamina_cost);
		getline(inputFile, garabage);

		Warrior* war = new Warrior(name, race, stoll(level), stoll(health), stoll(stamina));
		war->EquiptWeapon(weapon_name, stoll(weapon_damage), stoll(stamina_cost));

		getline(inputFile, garabage);
		getline(inputFile, name);
		getline(inputFile, race);
		getline(inputFile, level);
		getline(inputFile, health);		
		getline(inputFile, mana);
		getline(inputFile, num_of_spells);
		getline(inputFile, spell_name);
		getline(inputFile, spell_damage);
		getline(inputFile, mana_cost);

		Wizard* wiz = new Wizard(name, race, stoll(level), stoll(health), stoll(mana));
		wiz->addSpell(spell_name, stoll(spell_damage), stoll(mana_cost));

		getline(inputFile, spell_name);
		getline(inputFile, spell_damage);
		getline(inputFile, mana_cost);

		wiz->addSpell(spell_name, stoll(spell_damage), stoll(mana_cost));

		getline(inputFile, spell_name);
		getline(inputFile, spell_damage);
		getline(inputFile, mana_cost);

		wiz->addSpell(spell_name, stoll(spell_damage), stoll(mana_cost));

		Game startGame;
		startGame.AddCharacter(wiz);
		startGame.AddCharacter(war);

		while (!end_game)
		{
			cout << "Options: \nA: Play next turn.\nB: Print players status.\nQ: quit\n";
			cin >> choose;
			if (choose == 'A' || choose == 'a')
				startGame.NextTurn();
			else if (choose == 'b' || choose == 'B')
			{
				cout << "\n";
				war->print();
				cout << "\n";
				wiz->print();
				cout << "\n";
			}
			else if(choose == 'q' || choose == 'Q')
			{
				end_game = true;
			}
		}

	return 0;
}