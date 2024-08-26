#include <iostream>
#include <random>
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

int main() {

	setlocale(LC_ALL, "Russian");

	int fieldWidth, fieldHeight;
	do {
		system("cls");
		cout << "������� ������ ����" << endl;
		cout << "������: ";
		cin >> fieldWidth;
		cout << "������: ";
		cin >> fieldHeight;
	} while ((fieldHeight <= 2) || (fieldWidth <= 2));
	
	//�������� ����
	char** field = new char*[fieldHeight];
	for (int i = 0; i < fieldHeight; i++) {
		field[i] = new char[fieldWidth];
	}


	system("cls");
	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidth; j++) {
			cout << field[i][j];
		}
		cout << endl;
	}

	snakePiece snake;
	snakePiece sneakHead;

	//������ ���� �������� � ��������� �����
	snake.x = rand() % fieldWidth;
	snake.y = rand() % fieldHeight; 
	snake.next = NULL;
	snake.prev = NULL;


	return 0;
}