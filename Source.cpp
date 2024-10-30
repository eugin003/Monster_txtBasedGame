#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <filesystem>
#include <windows.h>
#include <winbase.h>
#include <vector>
#include <algorithm>
#include <D:\UNI\monstermaniac\monster.h>


using namespace std;

void Story();
void HUB();
void Combat();
void CombatHUB();
void Moving();
void CreateMonster();
void create_user();
void user_login(std::string);
void save();
void exit();
void FinishHUB();
void Scoreboard();


bool Intro = true;
std::string name = " ", race = " ", sex = " ", pw = " ";
int level = 0, Exp = 0, health = 0, totalHealth = 0, maxHealth = 0, toLevel = 0, heal = 0, id = 0;
std::string monsterNames[] = { "Goblin" , "Matue" , "Zeus" , "MC Frog" };
std::string currentMonster = " ";
int monsterHP = 0, monsterEXP = 0, monsterLevel = 0;
int totalMonsters = 0;
int counter = 0;
int score = 0;
vector<int> scoreboard;
vector<string> scorename;
Monster monster;
string FileName;



int main()
{
	system("cls");

	int op;
	std::cout << "\n\t\tWelcome to Monster&Maniac\n\n";
	std::cout << "1. Create Character\n2. Log In\n";
	std::cin >> op;

	if (op == 1) {
		create_user();
	}
	else if (op == 2) {
		user_login("");
	}
	else {
		std::cout << "Funny number ...\n";
		std::string lol = "L O L, bye\n";
		int i = 0;
		while (lol[i] != '\0') {
			std::cout << lol[i];
			if (i > 5) {
				Sleep(60);
			}
			else {
				Sleep(500);
			}
			i++;
		}
	}

	return 0;
}


void exit() {
	exit(0);
}

void save() {

		system("cls");
		score = Exp * counter;
		int op;
		int temp = 0;

		if (id == 0) {
			std::cout << "1. Save and Exit Game\n2. Exit Game\n3. Return back\n";
			std::cin >> op;
		}
		else {
			op = 1;
		}

		if (op == 2) {
			system("cls");
			std::cout << "If you leave now without saving your progress, all your data will be deleted from the system\nAre you"
				" sure that you want to leave?\n1. Yes\n2. No, Save and Exit\n";
			std::cin >> temp;
			if (temp == 1) {
				exit();
			}
		}

		if (op == 1 || (op == 2 && temp == 2)) {
			std::ofstream udFile;
			FileName = "Users\\" + name + ".txt";

			std::ofstream ofs;
			ofs.open(FileName, std::ofstream::out | std::ofstream::trunc);
			ofs.close();

			udFile.open(FileName, std::ios_base::app);

			udFile << id << ',' << score << ',' << name << "," << pw << ',' << race << "," << sex << "," << level << "," << Exp << "," <<
				health << "," << totalHealth << "," << maxHealth << "," << toLevel << "," << heal << ',' <<
				currentMonster << ',' << monsterEXP << ',' << monsterHP << ',' << monsterLevel << ',' << counter << ',' << totalMonsters <<'\n';

			// std::cout << "Saved successfully\n\n";
			udFile.close();
		}

		if (op == 3) {
			Sleep(400);
			CombatHUB();
			Combat();
		}

	
	if(id != 0){
		std::ofstream file;
		FileName = "Scoreboard\\board.txt";

		score = Exp * counter;
		
		file.open(FileName, std::ios_base::app);

		file << name << ',' << score << '\n';

		//std::cout << "Saved successfully\n\n";
		file.close();

		std::string endStory = "\"Ouch, that was a close one...\nOh man, what is that?\"\nYou got your eyes totally blinded by the helicopter flashlight.\n\n"
			"Turns out they were looking for you, well jobs done, you survived !\n";

		int i = 0;
		while (endStory[i] != '\0') {
			std::cout << endStory[i];
			Sleep(80);
			i++;
		}

		system("pause");

		FinishHUB();
	}else {
		exit();
	}
}

void user_login(std::string uname) {
	system("cls");
	std::ifstream file;
	std::string pwin;


	if (uname == "") {
		std::cout << "Username: ";
		std::cin >> uname;
		std::cout << "Password: ";
		std::cin >> pwin;
	}
	else {
		std::cout << "Username: " << uname << "\nPassword: ";
		std::cin >> pwin;
	}

	FileName = "Users\\" + uname + ".txt";
	std::string file_ = FileName;
	file.open(file_);

	bool found_record = false;

	std::string idstring, scorestring,namestring, pwstring, racestring, sexstring, levelstring, Expstring, healthstring, totalHealthstring,
		maxHealthstring, toLevelstring, healstring, currentMonsterstring, monsterEXPstring, monsterHPstring, totalmonsterstring, monsterLevelstring, counterstring;

	getline(file, idstring, ',');
	getline(file, scorestring, ',');
	getline(file, namestring, ',');
	getline(file, pwstring, ',');
	getline(file, racestring, ',');
	getline(file, sexstring, ',');
	getline(file, levelstring, ',');
	getline(file, Expstring, ',');
	getline(file, healthstring, ',');
	getline(file, totalHealthstring, ',');
	getline(file, maxHealthstring, ',');
	getline(file, toLevelstring, ',');
	getline(file, healstring, ',');
	getline(file, currentMonsterstring, ',');
	getline(file, monsterEXPstring, ',');
	getline(file, monsterHPstring, ',');
	getline(file, monsterLevelstring, ',');
	getline(file, counterstring, ',');
	getline(file, totalmonsterstring, '\n');


	if (idstring != "" && pwin == pwstring) {
		id = std::stoi(idstring);
		score = std::stoi(scorestring);
		name = namestring;
		pw = pwstring;
		race = racestring;
		sex = sexstring;
		level = std::stoi(levelstring);
		Exp = std::stoi(Expstring);
		heal = std::stoi(healthstring);
		totalHealth = std::stoi(totalHealthstring);
		maxHealth = std::stoi(maxHealthstring);
		toLevel = std::stoi(toLevelstring);
		heal = std::stoi(healstring);
		currentMonster = currentMonsterstring;
		monsterEXP = std::stoi(monsterEXPstring);
		monsterHP = std::stoi(monsterHPstring);
		monsterLevel = std::stoi(monsterLevelstring);
		counter = std::stoi(counterstring);
		totalMonsters = std::stoi(totalmonsterstring);

		if (id != 0) {
			FinishHUB();
		}

		if (currentMonster != " " && monsterHP > 0) {
			Combat();
			CombatHUB();
		}
		else {
			HUB();
			Moving();
		}
	}
	else {
		std::cout << "Wrong Password or Invalid User\n";
		Sleep(400);
		main();
	}
}

void create_user() {
	system("cls");
	std::cout << "Enter Characters Name: ";
	std::cin >> name;

	FileName = "Users\\" + name + ".txt";
	std::ifstream file;
	std::string file_ = FileName;

	file.open(file_);

	bool found_record = false;

	std::string id, namestring, next, prev;


	while (getline(file, id, ',') && !found_record) {
		getline(file, prev, ',');
		getline(file, namestring, ',');
		getline(file, next, '\n');
		if (namestring == name) {
			found_record = true;
		}
	}

	if (!found_record) {
		std::cout << "Enter Characters Password: ";
		std::cin >> pw;
		std::cout << "Enter Characters Race: ";
		std::cin >> race;
		std::cout << "Enter Characters Sex: ";
		std::cin >> sex;
		system("cls");
		std::cout << "Creating Character .\n";
		Sleep(1000);
		system("cls");
		std::cout << "Creating Character ..\n";
		Sleep(1000);
		system("cls");
		std::cout << "Creating Character ...\n";
		Sleep(1100);
		system("cls");
		Intro = true;
	}
	else {
		int op;
		std::cout << "\nCharacter already exists ...\n\n\n";
		std::cout << "1. Log in\n2. Go back\n\n";
		std::cin >> op;
		if (op == 1)
		{
			file.close();
			user_login(name);
		}
		else if (op == 2) {
			file.close();
			create_user();
		}
		else {
			std::cout << "\nFunny number ...\n";
			std::string lol = "L O L, bye\n";
			int i = 0;
			while (lol[i] != '\0') {
				std::cout << lol[i];
				if (i > 5) {
					Sleep(75);
				}
				else {
					Sleep(400);
				}
				i++;
			}
		}
		system("cls");
		file.close();
		exit();
	}

	level = 1;
	Exp = 0;
	toLevel = 54;
	health = 100;
	totalHealth = 100;
	maxHealth = totalHealth;

	Story();
	HUB();
	Moving();
}

void HUB()
{
	Sleep(400);
	system("cls");
	std::cout << "Name: " << name << "\t\tHealth: " << totalHealth << "\t CODE:'51486' to Save & Leave Game" <<
		"\nRace: " << race << "\nSex: " << sex << "\nLevel: " << level << "\nExp: " << Exp << "\nExp to Level: " << toLevel << std::endl;
}

void CombatHUB()
{
	Sleep(1000);
	system("cls");
	std::cout << "Name: " << name << "\t\tMonster Name: " << currentMonster << "\t CODE:'51486' to Save & Leave Game" << "\nHealth: " << totalHealth <<
		"\t\tMonster Health: " << monsterHP << "\nLevel: " << level << "\t\tMonster Level: " << monsterLevel << std::endl;
}

void Combat()
{
	CombatHUB();
	int playerAttack;
	int playerDamage = 8 * level / 2;
	int monsterAttack = 6 * monsterLevel / 3;

	if (totalHealth >= 1 && monsterHP >= 1) {
		std::cout << std::endl;
		std::cout << "1. Attack" << std::endl;
		std::cout << "2. Block" << std::endl;
		std::cout << "3. RUN!" << std::endl;
		std::cout << std::endl << std::endl;
		std::cin >> playerAttack;

		if (playerAttack == 1) {

			std::cout << "Attacking you did " << playerDamage << " to the " << currentMonster << std::endl;
			monsterHP = monsterHP - playerDamage;
			Sleep(500);
			CombatHUB();

			if (monsterHP >= 1) {
				std::cout << "\n\n";
				std::cout << "Monster is Attacking ... " << std::endl;
				totalHealth = totalHealth - monsterAttack;
				std::cout << "You suffer " << monsterAttack << " hp\tTotal health:  " << totalHealth << std::endl;
				if (totalHealth <= 0) {
					totalHealth = 0;
				}
			}
			else if (monsterHP <= 0) {
				monsterHP = 0;
			}
			Sleep(2000);
			CombatHUB();
			Combat();
		}
		else if (playerAttack == 2) {
			std::cout << "\n\nBlocking!" << std::endl;
			int i = rand() % 100 + 1;
			if (i >= 50) {
				std::cout << "\nYou Blocked incoming attack!" << std::endl;
				heal = maxHealth - totalHealth;
				std::cout << "You healed! " << heal << " hp to your total health" << std::endl;
				totalHealth += heal;
				Sleep(3500);
				CombatHUB();
				Combat();
			}
			else {
				std::cout << "\n\nYou failed to block monsters attacks" << std::endl;
				totalHealth = totalHealth - monsterAttack;
				std::cout << "You suffer " << monsterAttack << " hp\tTotal Health: " << totalHealth << std::endl;
				Sleep(3500);
				CombatHUB();
				Combat();
			}
		}
		else if (playerAttack == 3) {
			std::cout << "You try to run away!" << std::endl;
			int x = rand() % 100 + 1;
			if (x >= 50) {
				std::cout << "You ran away!" << std::endl;
				Sleep(1000);
				HUB();
				Moving();
			}
			else {
				std::cout << "\n\nYou failed to run away!" << std::endl;
				std::cout << "Monster Attack!" << std::endl;
				totalHealth = totalHealth - monsterAttack;
				std::cout << "You suffer " << monsterAttack << " hp\tTotal Health: " << totalHealth << std::endl;
				Sleep(3500);
				CombatHUB();
				Combat();
			}
		}
		else if (playerAttack == 51486) {
			save();
		}
		else {
			std::cout << "ERROR 13: Non available option" << std::endl;
			Sleep(500);
			CombatHUB();
			Combat();
		}
	}

	if (totalHealth <= 1) {
		system("cls");
		std::cout << "You died! " << std::endl << "You were level: " << level <<
			"\nYou got killed by " << currentMonster << std::endl;
		system("pause");
		exit();
	}

	if (monsterHP <= 1) {
		HUB();
		Exp += monsterEXP;
		std::cout << "\n\nYou defeated " << currentMonster << " you are rewarded with " << monsterEXP << " exp.\nWell Done!\n" << std::endl;
		system("pause");
		counter++;
		if (counter == totalMonsters) {
			id = 1;
			save();
		}
	}

	if (Exp >= toLevel) {
		level++;
		totalHealth = 100;
		totalHealth += 20 * level;
		maxHealth = totalHealth;
		std::cout << "\n\nLevel up! You are now level: " << level << "\n";
		std::cout << "You total health increased by 20 points! Max health now is: " << totalHealth << "\n";
		Sleep(2000);
		HUB();
		toLevel = toLevel + toLevel * 2;
	}
	system("pause");
	HUB();
	Moving();
}

void CreateMonster()
{
	monsterLevel = (rand() % 5 + 1);
	if (monsterLevel >= 3) {
		monsterEXP = (rand() % 50 + 1) + (monsterLevel * 5);
		monsterHP = (rand() % 70 + 40) + (monsterLevel * 10);
	}
	else {
		monsterEXP = (rand() % 25 + 1) + (monsterLevel * 5);
		monsterHP = (rand() % 50 + 20) + (monsterLevel * 10);
	}

	monster.setHP(monsterHP);
	monster.setEXP(monsterEXP);
	monster.setLevel(monsterLevel);
	monster.setName(currentMonster);

	monsterHP = monster.getHP();
	monsterEXP = monster.getEXP();
	monsterLevel = monster.getLevel();
	currentMonster = monster.getName();
}

void Moving() {

	int choice;

	std::cout << std::endl;
	std::cout << "1. Move Forward" << std::endl;
	std::cout << "2. Relax" << std::endl;
	std::cout << "3. Move Backward" << std::endl;
	std::cout << std::endl << std::endl;
	std::cin >> choice;

	if (choice == 1) {
		int temp = rand() % 100 + 1;
		std::cout << "You are running forward..." << std::endl;
		if (temp >= 50) {
			currentMonster = monsterNames[rand() % 3 + 1];
			CreateMonster();
			std::cout << "A Monster! Prepare to fight a " << monster.getName() << std::endl;
			Sleep(700);
			Combat();
		}
		else {
			std::cout << "You find nothing of interest!" << std::endl;
			Sleep(500);
			HUB();
			Moving();
		}
	}
	else if (choice == 2) {
		std::cout << "You want to chill out for a sec" << std::endl;
		if (counter % 2 == 0) {
			if (totalHealth <= 99) {
				totalHealth += 10 * level;
				if (totalHealth > 100 && level == 1) {
					totalHealth = 100;
				}
				else if (totalHealth > 120 && level == 2) {
					totalHealth = 120;
				}
				else if (totalHealth > 140 && level == 3) {
					totalHealth = 140;
				}
				else if (totalHealth > 160 && level == 4) {
					totalHealth = 160;
				}
			}
			std::cout << "You healed by resisting! Health is now at  " << totalHealth << " hp" << std::endl;
		}
		else {
			std::cout << "You resisted but did not heal. You feel stiff from sitting for too long." << std::endl;
		}
		Sleep(500);
		HUB();
		Moving();
	}
	else if (choice == 3) {
		int temp = rand() % 100 + 1;
		std::cout << "You are running backwards ..." << std::endl;
		if (temp >= 50) {
			currentMonster = monsterNames[rand() % 3 + 1];
			CreateMonster();
			std::cout << "A Monster! Prepare to fight a " << monster.getName() << std::endl;
			Sleep(700);
			Combat();
		}
		else {
			std::cout << "You find nothing of interest!" << std::endl;
			Sleep(300);
			HUB();
			Moving();
		}
	}
	else if (choice == 51486) {
		save();
	}
	else {
		std::cout << "ERROR 13: Non available option" << std::endl;
		Sleep(500);
		HUB();
		Moving();
	}

}

void Story() {
	std::string introStory = "You waken to darkness, you can't see nothing but the smell is bitter\n"
		"The breeze cuts through your skin like broken glass, try and remember what happened?\n"
		"\"Where am I?\" You think and remember a pub and the day is about to end.\n"
		"\"Well... Better start a fire, I guess ...\" \n\n";

	if (Intro) {
		int i = 0;
		while (introStory[i] != '\0') {
			std::cout << introStory[i];
			Sleep(60);
			i++;
		}
		Intro = false;
		system("pause");
	}

	totalMonsters = rand() % 13 + 10;

	system("cls");
	std::cout << "Clearing Console .";
	Sleep(450);
	system("cls");
	std::cout << "Clearing Console ..";
	Sleep(450);
	system("cls");
	std::cout << "Clearing Console ...";
	Sleep(450);
	system("cls");
	std::cout << "Console Clearing Resuming";
	Sleep(450);
}

void FinishHUB() {
	int opt;
	system("cls");
	Sleep(500);
	std::cout << "Congratulations " << name << " !!\nYou have finished the game!\n\n" << std::endl;
	std::cout << "1. Scoreboard\n2. Exit Game\n";
	std::cin >> opt;

	if (opt == 1) {
		Scoreboard();
	}
	else {
		exit();
	}
}

void Scoreboard() {

	system("cls");
	std::ifstream file, file2;
	FileName = "Scoreboard\\board.txt";
	file.open(FileName, std::ios_base::app);
	file2.open(FileName, std::ios_base::app);

	int _score, temp;
	std::string _name, name, score, score2, name2;


	while (!file.eof())
	{

		getline(file, name, ',');
		getline(file, score, '\n');

		if (name == "" || score == "") {
			break;
		}

		_score = std::stoi(score);

		scoreboard.insert(scoreboard.begin(), _score);

	}
	file.close();


	std::sort(scoreboard.begin(), scoreboard.end(), [](int a, int b)
		{
			return a > b;
		});

	std::cout << "\n\n\t\tSCORE BOARD\n\n\tNAME\t\tSCORE\n\n";
	int j = 0;
	while (true) {
		file2.open(FileName, std::ios_base::app);
		while (!file2.eof()) {

			getline(file2, name2, ',');
			getline(file2, score2, '\n');

			if (name2 == "" || score2 == "") {
				break;
			}

			temp = std::stoi(score2);


			if (temp == scoreboard[j])
			{
				scorename.insert(scorename.begin() + j, name2);
				j++;
				break;
			}

		}
		file2.close();
		if (j == scoreboard.size()) {
			break;
		}
	}

	for (int i = 0; i < scoreboard.size();i++) {
		std::cout << "\n\t" << scorename[i] << "\t\t" << scoreboard[i] << "\n";
	}

	std::cout << "\n\n\n\n";
	system("pause");
	FinishHUB();
}

