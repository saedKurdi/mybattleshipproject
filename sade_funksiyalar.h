#pragma once
#pragma once
#include<iostream>
#include<conio.h>
#include<iomanip>
#include <Windows.h>
using namespace std;

void SetColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

int** CreateArray(int size) {
	int** Game = new int* [size] {};
	for (size_t i = 0; i < size; i++)
	{
		Game[i] = new int[size] {};
	}

	return Game;
}


void ShowArea(int** game, int size) {
	for (size_t i = 0; i < size; i++)
	{
		for (size_t k = 0; k < size; k++)
		{
			if (i == 0) {
				cout << setw(2) << (char)(48 + k) << " ";
			}
			else if (k == 0) {
				cout << setw(2) << (char)(48 + i) << " ";
			}
			else if (game[i][k] == 0) {
				SetColor(9);
				cout << setw(2) << (char)254 << " ";
				SetColor(7);
			}
			else if (game[i][k] == 1) {
				SetColor(6);
				cout << setw(2) << (char)254 << " ";//gemi var
				SetColor(7);
			}
			else if (game[i][k] == 5) {
				SetColor(4);
				cout << setw(2) << (char)254 << " ";// vuruldu gemi partladi
				SetColor(7);
			}
		}cout << endl;
	}cout << endl << endl << endl;
}

void MainMenu() {
	cout << "\t\t\t\t W E L C O M E   T O   B A T T L E S H I P " << endl << endl << endl;
	cout << "1 . M A N U A L " << endl << endl << endl;
	cout << "2 . A U T O " << endl << endl << endl;
	cout << "3 . A B O U T   O U R   G A M E " << endl << endl << endl;;
	cout << "4 . <----   E X I T   F R O M   G A M E " << endl << endl;;
}


void AboutGame() {
	cout << "Battleship is a classic two-player guessing game where each player tries to sink their opponent's fleet of ships by guessing the coordinates" << endl << endl;
	cout << "of where their ships are located on a grid Here are the basic rules of the game : " << endl << endl;
	cout << "Each player has their own grid where they place their ships. The size and number of ships can vary, but the most common setup has 5 ships" << endl << endl;
	cout << "one carrier (5 spaces), one battleship (4 spaces), one cruiser (3 spaces), one submarine (3 spaces), and one destroyer (2 spaces)" << endl << endl;
	cout << "Players take turns guessing the coordinates of their opponent's ships by calling out a row and column letter (e.g. 'B4')." << endl << endl;
	cout << "If the guess is a hit, the player marks that spot on their opponent's grid as a hit. If the guess is a miss, they mark it as a miss." << endl << endl;
	cout << " If a player sinks all of their opponent's ships, they win the game. " << endl << endl;;
}


bool IsEmpty(int** arr, int Y, int X, char direction, int sizeofship) {
	int count = 0;
	if (direction == 'l') {// left
		for (size_t i = 0; i <= sizeofship; i++)
		{
			if (arr[Y][X - i] == 0 && arr[Y + 1][X - i] == 0 && arr[Y - 1][X - i] == 0 && arr[Y][X + 1] == 0 && arr[Y + 1][X + 1] == 0 && arr[Y - 1][X + 1] == 0) {
				count++;
			}
		}
	}
	else if (direction == 'r') {// right
		for (size_t i = 0; i <= sizeofship; i++)
		{
			if (arr[Y][X + i] == 0 && arr[Y + 1][X + i] == 0 && arr[Y - 1][X + i] == 0 && arr[Y][X - 1] == 0 && arr[Y + 1][X - 1] == 0 && arr[Y - 1][X - 1] == 0) {
				count++;
			}
		}
	}
	else if (direction == 'd') {// down
		for (size_t i = 0; i <= sizeofship; i++)
		{
			if (arr[Y + i][X] == 0 && arr[Y + i][X + 1] == 0 && arr[Y + i][X - 1] == 0 && arr[Y - 1][X] == 0 && arr[Y - 1][X + 1] == 0 && arr[Y - 1][X - 1] == 0) {
				count++;
			}
		}
	}
	else if (direction == 'u') {// up
		for (size_t i = 0; i <= sizeofship; i++)
		{
			if (arr[Y - i][X] == 0 && arr[Y - i][X + 1] == 0 && arr[Y - 1][X - 1] == 0 && arr[Y + 1][X] == 0 && arr[Y + 1][X - 1] == 0 && arr[Y + 1][X + 1] == 0) {
				count++;
			}
		}
	}
	if (count == sizeofship + 1) {
		return true;
	}
	return false;
}


void SetShips(int** arr, int row, int col, char direction, int sizeofship) {
	if (direction == 'l') {
		for (size_t i = 0; i < sizeofship; i++)
		{
			arr[row][col - i] = 1;
		}
	}
	else if (direction == 'r') {
		for (size_t i = 0; i < sizeofship; i++)
		{
			arr[row][col + i] = 1;
		}
	}
	else if (direction == 'd') {
		for (size_t i = 0; i < sizeofship; i++)
		{
			arr[row + i][col] = 1;
		}
	}
	else if (direction == 'u') {
		for (size_t i = 0; i < sizeofship; i++)
		{
			arr[row - i][col] = 1;


		}
	}
	else {
		cout << "Please enter true direction ! " << endl;
	}
}


