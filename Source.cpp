#include<iostream>
using namespace std;

string WeaponsAndArmor[6] = { "G0LD HAMM3R", "G0LD S1CK13", "proof vest", "epic kick", "epick dagger", "walmart light saber" };
string items[3] = { "health potion", "smoke bomb", "ham" };
int itemNum[3] = { 2,5,1 };
int PlayerHealth = 100;

void BattleSystem(int MonsterType);

int main() {

	int put;
	do {
		cout << "Get ready to fight noob!" << endl; //numbers are different
		PlayerHealth = 100; //reset health just for testing
		
		BattleSystem(rand()% 5+1);
	} while (PlayerHealth > 0);
	cout << "goodbye" << endl;
}

//function deffinition
void BattleSystem(int MonsterType) {
	
	int MonsterHealth;
	int damage;
	char input;
	int input2;
	bool CanRun = false;
	bool SmokeCloud = false;

	switch (MonsterType) {
	case 1: 
		cout << "GOERGY MALENKOV resurrects!" << endl;
		MonsterHealth = 20;
		break;
	case 2:
		cout << "THE EPIC RASPUTIN ressurects!" << endl;
		MonsterHealth = 200;
		break;
	case 3:
		cout << "JOSEPH STALIN reusurrects!" << endl;
		MonsterHealth = 60;
		break;
	case 4:
		cout << "VLADIMIR LENIN resurrects!" << endl;
		MonsterHealth = 100;
		break;
	case 5:
		cout << "THE MAJESTIC KEANU REEVES!" << endl;
		MonsterHealth = 150;
		break;
	}

	//battle loop
	while (MonsterHealth >= 0 && PlayerHealth >= 0 && CanRun == false) {

		cout << endl << endl << "He currently has " << MonsterHealth << "HP left" << endl;
		cout << "Your HP is " << PlayerHealth << endl;
		cout << "Press 'f' to fight, 'i' to use item, 'r' to run." << endl;
		cin >> input;
		switch (input) {

			//FIGHT CASE////////////////////////////
		case 'f':
			//flame sword hits harder on ice enemies
			if (MonsterType == 2 && WeaponsAndArmor[0].compare("epic dagger") == 0) {
				damage = rand() % 20;
				cout << "Your epic dagger gently hurts him for " << damage << " damage." << endl;
			}
			//ice wand hits harder on fire enemies
			else if (MonsterType == 3 && WeaponsAndArmor[2].compare("epic kick") == 0) {
				damage = rand() % 10;
				cout << "Your epic kick hits him in the face for " << damage << " damage." << endl;
			}
			else { //no special weapon used
				damage = rand() % 30;
				cout << "You swing your walmart light saber for " << damage << " damage." << endl;

			}

			MonsterHealth -= damage;
			break;

			//ITEM CASE///////////////////////////////////
		case 'i':
			cout << "Press 1 to use medic kit, 2 to use smoke bomb, 3 to use religeus coment." << endl;
			cin >> input2;

			//check if you have a health potion, if you do, add to players health and subtract frim items
			if (itemNum[input2-1] <= 0)
				cout << "Sorry, you don't have any left." << endl;
			else if (input2 == 1) {
				cout << "glug, glug" << endl;
				PlayerHealth += 20;
				itemNum[0] -= 1;
			}
			else if (input2 == 2) {
				cout << "POOF" << endl;
				itemNum[1] -= 1;
				SmokeCloud = true;
			}
			else if (input2 == 3) {
				cout << "You dropped the ham on the ground with a thud." << endl;
				if (MonsterType == 3) {
					cout << "The dragon greedily grabs it and flies away." << endl;
				}
				else
					cout << "The monsters briefly eye the ham with suspicion, then turn their attention back at you." << endl;

			}
			break;
			
		//VIEW ITEMS CASE///////////////////////////////////////
		case 'v':
			cout << "Your items " << endl;
			for (int w = 0; w < 3; w++)
				cout << itemNum[w] << " " << items[w] << endl;
			break;

			//RUN CASE///////////////////////////////////////
		case 'r':
			if (SmokeCloud == true) {
				if (rand() % 10 > 8) {
					cout << "The smoke hides your escape!" << endl;
					CanRun = true;
				}
				}
			else if (rand() % 10 > 4) {
					cout << "Your luck holds and you are able to run away succesfully!" << endl;
					CanRun = true;
			}
			else
					cout << "The enemy blocks your way and you cannot run." << endl;
			break;

		default:
			cout << "Sorry, Me not get it" << endl;
		}//end swithch

		//MONSTER ATTACK/////////////////////////////////////
		
		if (MonsterType == 1) {
			damage = rand() % 20 + 10;
			cout << "GEORGY MALENKOV uses politics for " << damage << endl;
			PlayerHealth -= damage;
		}
		if (MonsterType == 3) {
			damage = rand() % 5 + 10;
			cout << "STALIN uses his mustache for " << damage << endl;
			PlayerHealth -= damage;
		}
		if (MonsterType == 4) {
			damage = rand() % 20;
			cout << "LENIN uses revolution for " << damage << endl;
			PlayerHealth -= damage;
		}
		if (MonsterType == 5) {
			damage = rand() % 40;
			cout << "KEANU REEVES uses being breath taking for " << damage << endl;
			PlayerHealth -= damage;
		}
		if (MonsterType == 2) { //dragon has two possible attacks!
			if (rand() % 10 < 5) {
				damage = rand() % 80 + 10;
				cout << "RASPUTIN uses throw in ice river " << damage << endl;
				if (WeaponsAndArmor[1].compare("proof vest") == 0) {
					cout << "Your your proof vest absorbs 20 damage!" << endl;
					damage -= 20;
				}
			}
			else {
				damage = rand() % 50 + 20;
				cout << "Rasputin uses religion " << damage << endl;
			}
			PlayerHealth -= damage;
		}
		if (MonsterHealth <= 0)
			cout << "He is defeated!" << endl;

		if (PlayerHealth <= 0)
			cout << "You dead boi!" << endl;

	}//end battle loop

}//end function definition