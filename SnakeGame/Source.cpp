#include <iostream>
#include <random>
using namespace std;

struct snakePiece {
	int x, y;
	snakePiece* next;
	snakePiece* prev;
};

int main() {

	setlocale(LC_ALL, "Russian");

	int fieldWidht, fieldHeight;
	do {
		system("cls");
		cout << "������� ������ ����" << endl;
		cout << "������: ";
		cin >> fieldWidht;
		cout << "������: ";
		cin >> fieldHeight;
	} while ((fieldHeight <= 2) || (fieldWidht <= 2));
	
	//�������� ����
	char** field = new char*[fieldHeight];
	for (int i = 0; i < fieldHeight; i++) {
		field[i] = new char[fieldWidht];
	}


	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidht; j++) {
			field[i][j] = ' ';
		}
	}
	system("cls");
	for (int i = 0; i < fieldHeight; i++) {
		for (int j = 0; j < fieldWidht; j++) {
			cout << field[i][j];
		}
		cout << endl;
	}

	snakePiece snake;
	snakePiece sneakHead;

	//������ ���� �������� � ��������� �����
	snake.x = rand() % fieldWidht;
	snake.y = rand() % fieldHeight;

	return 0;
}