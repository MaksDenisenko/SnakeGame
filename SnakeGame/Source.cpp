#include <iostream>

using namespace std;

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

	return 0;
}