#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

const int width = 60;
const int height = 30;

int x, y;
int fructX, fructY;
int score;
int tailY[100], tailX[100];
int tail;
enum snakeDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
snakeDirection sd;
bool isOver;


void Init() {
	isOver = false;
	sd = STOP;
	fructX = rand() % width + 1;
	fructY = rand() % height + 1;
	x = width / 2;
	y = height / 2;
	score = 0;
}

void Render(string PlayerName) {
	system("cls");
	for (int i = 0; i <= height; i++) {
		for (int j = 0; j <= width; j++) {
			if ((j == 0) || (j == width)) {
				cout << "|";
			}
			else if ((i == 0) || (i == height)) {
				cout << "-";
			}
			else if (i == y && j == x)
				cout << "O";
			else if (i == fructY && j == fructX)
				cout << "x";
			else {
				bool prTail = false;
				for (int k = 0; k < tail; k++) {
					if (tailX[k] == j && tailY[k] == i) {
						cout << "o";
						prTail = true;
					}
				}
				if (!prTail)
					cout << " ";
			}
		}
		cout << endl;

	}
	cout << PlayerName << "'s score is: " << score<<endl;
}

void UpdateGame() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < tail; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (sd) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x >= width || x == 0 || y >= height || y == 0) {
		isOver = true;
	}
	if (x == fructX && y == fructY) {
		score += 1;
		fructX = rand() % width + 1;
		fructY = rand() % height + 1;
		tail++;
	}
}

void UserInput() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			sd = LEFT;
			break;
		case 'w':
			sd = UP;
			break;
		case 'd' : 
			sd = RIGHT;
			break;
		case 's':
			sd = DOWN;
			break;
		case 'n':
			isOver = true;
			break;
		}
	}
}

void main() {
	string playerName;
	int dif;
	cout<<"What is the player's name?" << endl;
	cin >> playerName;
	cout << "What difficulty do you wish to play at?\n1-easy\n2-medium\n3-hard\n4-hardcore\n";
	cin >> dif;
	switch (dif) {
	case(1):
		dif = 250;
		break;
	case(2):
		dif = 200;
		break;
	case(3):
		dif = 100;
		break;
	case(4):
		dif = 5;
		break;
	}
	Init();
	Render(playerName);
	while (!isOver) {
		UserInput();
		UpdateGame();
		Render(playerName);
		Sleep(dif);
	}
}
