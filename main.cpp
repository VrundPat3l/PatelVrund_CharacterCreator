#include<iostream>
#include<conio.h>
#include <time.h>
using namespace std;

// Define Equipment structs :
struct Equipment
{
	// Member variables :
	string name;
	int attack;
	int defense;
	int dexterity;

	// A function that prints all member variables in a readable way
	void PrintName()
	{
		cout << "Name:      " << name << "\n";
		cout << "Attack:    " << attack << "\n";
		cout << "Defense:   " << defense << "\n";
		cout << "Dexterity: " << dexterity << "\n";
	}
};

// Define RpgCharacter structs :
struct RpgCharacter
{
	// Member variables :
	string name;
	int attack;
	int defense;
	int dexterity;
	int hp;
	Equipment* weapon;
	Equipment* armor;

	// A function that prints the character’s name and all stats, including equipment.
	void PrintCharacter()
	{
		cout << "Name:      " << name << "\n";
		cout << "Hp:        " << hp << "\n";
		cout << "Dexterity: " << dexterity << "\n";

		if (weapon != nullptr)													    // if statement with coindition weapon not equal to nullptr
		{																		    
			attack += weapon->attack;											    // if condition is true then add the weapon's attack power to characters attack power
		}																		    
		cout << "Attack:    " << attack << "\n";								    
		if (weapon != nullptr)													    // if statement with coindition weapon not equal to nullptr
		{
			cout << " (+" << weapon->attack << " from " << weapon->name << ") \n";	// if condition is true then printing the amount of power get from weapon
		}

		if (armor != nullptr)													    // if statement with coindition armor not equal to nullptr
		{																		    
			defense += armor->defense;											    // if condition is true then add the weapon's defense power to characters defense power
		}																		    
        cout << "Defense:   " << defense << "\n";								    
		if (armor != nullptr)													    // if statement with coindition armor not equal to nullptr
		{																		    
			cout << " (+" << armor->defense << " from " << armor->name << ") \n";	// if condition is true then printing the amount of power get from armor
		}
	}
};

// function to print stuff and choose weapon and armor
void PrintStuff()
{
	srand(unsigned(time(nullptr)));
	int random = rand() % 50 + 1;

	cout << "Welcome To RPG Game\n";
	cout << "Press Enter to Play Game...\n";
	cin.ignore();
	system("cls");

	// Create at least 2 Equipment instances to represent weapons.
	Equipment sword{ "Sword", 2, 1, -1 };
	Equipment axe{ "Axe", 4, 0, -2 };
	// Create at least 2 Equipment instances to represent armor
	Equipment leather{ "Leather", 0, 2, -1 };
	Equipment chain{ "Chain", 0, 3, -2 };

	RpgCharacter character;

	// Start by asking the user to enter their character’s name and the values of their stats.
	cout << "Enter Your Character's Name \n";
	cin >> character.name;
	cout << "You want to type or get random stats?\n";
	cout << "1) Type\n";
	cout << "2) Random\n";
	
	char choice = _getch();
	// switch statement to type or random
	switch (choice)
	{
	case'1':
		cout << "Enter Your Character's HP \n";
		cin >> character.hp;
		cout << "Enter Your Character's attacking power \n";
		cin >> character.attack;
		cout << "Enter Your Character's Defense \n";
		cin >> character.defense;
		cout << "Enter your character's Dexterity\n";
		cin >> character.dexterity;
	case'2':
		character.hp = random;
		random = rand() % 50 + 1;
		character.attack = random;
		random = rand() % 50 + 1;
		character.defense = random;
		random = rand() % 50 + 1;
		character.dexterity = random;
	}
	
    // Ask the user to pick a weapon for their character in the following way:
	cout << "Pick a weapon for your character: \n";

	
	// Display a menu containing the weapon options
	cout << "1) Sword: attack: 2, defense: 1, dexterity: -1 \n";
	cout << "2) Axe:   attack: 4, defense: 0, dexterity: -2 \n";
	cout << "3) No Weapon \n";															 // Also display an option to have no weapon

	// Taking user choice to choose weapon
	char weaponchoice = _getch();

	//// switch statement to choose weapon
	switch (weaponchoice)
	{
	case '1':
		character.weapon = &sword;
		break;

	case '2':
		character.weapon = &axe;
		break;

	default:
		character.weapon = nullptr;
		cout << "you choose nothing \n";
		break;
    }

	// Ask the user to pick a Armour for their character
    cout << "Pick a Armour for your character: \n";

	// Menu containing the armour options
	cout << "1) Leather: attack: 0, defense: 2, dexterity: -1\n";
	cout << "2) Chain: attack: 0, defense: 3, dexterity: -2\n";
	cout << "3) No Armor \n";																 // Also display an option to have no armor.

	// Taking user choice to choose Armour
	char Armorchoice = _getch();

	// switch statement to choose amor
	switch (Armorchoice)
	{
	case '1':
		character.armor = &leather;
		break;

	case '2':
		character.armor = &chain;
		break;

	default:
		character.armor = nullptr;														  //  Having no armor must be represented by a null pointer.
		cout << "you choose nothing\n";
		break;
	}
	system("cls");

	//Once all choices have been made, call the character’s print function to print the character sheet.
	character.PrintCharacter();
}

int main()
{
	PrintStuff();
    return 0;
}