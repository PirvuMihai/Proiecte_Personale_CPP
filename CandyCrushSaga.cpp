#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

int height = 21;
int length = 11;
string arr[25][25];
int score = 0;
bool isOver = 0;

void TableRender() {
	system("cls");
	string* colors = new string[3];
	colors[0] = "B";
	colors[1] = "G";
	colors[2] = "R";
	for (int i = 0; i <= height; i++) {
		for (int j = 0; j <= length; j++) {
			if (i == 21 && j % 2 == 1 && j != 11)
				arr[i][j] = to_string(j / 2 + 1);
			if (j == 11 && i % 2 == 1 && i != 21)
				arr[i][j] = to_string(i / 2 + 1);
			else if (j % 2 == 0)
				arr[i][j] = "|";
			else if (i % 2 == 0)
				arr[i][j] = "-";
			else if (i % 2 == 1 && j % 2 == 1 && i != 21) {
				int num = rand() % 3;
				if (num == 0) {
					arr[i][j] = colors[num];
				}
				if (num == 1) {
					arr[i][j] = colors[num];
				}
				if (num == 2) {
					arr[i][j] = colors[num];
				}
			}
		}
	}

}

void ShowTable() {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i <= height; i++) {
		for (int j = 0; j <= length; j++) {
			if (arr[i][j] == "R")
				SetConsoleTextAttribute(hConsole, 4);
			else if (arr[i][j] == "G")
				SetConsoleTextAttribute(hConsole, 2);
			else if (arr[i][j] == "B")
				SetConsoleTextAttribute(hConsole, 1);
			else
				SetConsoleTextAttribute(hConsole, 8);
			cout << arr[i][j];
		}
		cout << endl;
	}
}
//
//void InitialTableCheck() {
//	int c = 0;
//	int k = 0;
//	for (int i = 0; i <= height; i++) {
//		for (int j = 0; j <= length; j++) {
//			if (arr[i][j] == arr[i][j + 1]) {
//				c = 2;
//				k = 2;
//				while (c+j != length) {
//					if (arr[i][j] == arr[i][c + j])
//						k++;
//					j++;
//				}
//				for (int j = length - k; j <= length; j++) {
//					if()
//			}
//			}
//		}
//	}
//}

void main()
{
	while (!isOver) {
		TableRender();
		ShowTable();
		isOver = true;
	}
}
