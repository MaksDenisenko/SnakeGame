#include <iostream>
#include <random>
#include <conio.h>
using namespace std;

struct snakePiece {
	int x, y;
	snakePiece* next;
	snakePiece* prev;
};

void printField(char** field, int fieldHeight, int fieldWidth) {
	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidth; j++) {
			cout << field[i][j];
		}
		cout << endl;
	}
}

void clearField(char** field, int fieldHeight, int fieldWidth) {
	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidth; j++) {
			field[i][j] = ' ';
		}
	}
}

void setFigures(char** field, int fieldHeight, int fieldWigth, snakePiece* snake) {
	
}

int main() {

	setlocale(LC_ALL, "Russian");

	int fieldWidth, fieldHeight;
	do {
		system("cls");
		cout << "Введите размер поля" << endl;
		cout << "Ширина: ";
		cin >> fieldWidth;
		cout << "Высота: ";
		cin >> fieldHeight;
	} while ((fieldHeight <= 2) || (fieldWidth <= 2));
	
	//Создание поля
	char** field = new char*[fieldHeight];
	for (int i = 0; i < fieldHeight; i++) {
		field[i] = new char[fieldWidth];
	}

	clearField(field, fieldHeight, fieldWidth);
	system("cls");
	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidth; j++) {
			cout << field[i][j];
		}
		cout << endl;
	}

	snakePiece snake;
	snakePiece* sneakHead = &snake;

	//Голова змеи ставится в рандомное место
	snake.x = rand() % fieldWidth;
	snake.y = rand() % fieldHeight; 
	snake.next = NULL;
	snake.prev = NULL;
	
	bool lively = true;
	char symbol; //Считывание символа, введенного пользователем

	int currentLength = 0;

	while (lively) {
		symbol = _getch();
		
		if (symbol == 'w') {
			snake.y -= 1;
			if (snake.y < 0) snake.y = fieldHeight - 1;
		}
		if (symbol == 'd') {
			snake.x = (snake.x + 1) % fieldWidth;
		}
		if (symbol == 's') {
			snake.y = (snake.y + 1) % fieldHeight;
		}
		if (symbol == 'a') {
			snake.x -= 1;
			if (snake.x < 0) snake.x = fieldWidth - 1;
		}
		snakePiece* snakeCurrent = sneakHead;
		currentLength = 0;
		clearField(field, fieldHeight, fieldWidth);
		while (snakeCurrent != NULL) {
			if (currentLength == 0) field[snakeCurrent->y][snakeCurrent->x] = 'O';
			else field[snakeCurrent->y][snakeCurrent->x] = '@';

			currentLength++;
			snakeCurrent = snakeCurrent->next;
		}
		system("cls");
		printField(field, fieldHeight, fieldWidth);
	}

	return 0;
}