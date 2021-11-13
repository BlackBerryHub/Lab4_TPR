#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double read_file_w(double weight[5]) {
	ifstream in("weight.txt");
	if (in.is_open())
	{

		for (int i = 0; i < 5; i++)
			in >> weight[i];

		cout << "\t";
		for (int i = 0; i < 5; i++)
		{
			cout << weight[i] << "\t\t";
		}
		cout << endl << "   -------------------------------------------------------------------------------" << endl;
		in.close();
		return *weight;
	}
	else
	{
		cout << "Файл не знайдено.";
		return *weight;
	}
}

char read_file_r(int ranks[5][5], char cars[5]) {
	ifstream in("ranks.txt");
	if (in.is_open())
	{
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				in >> ranks[i][j];
			}
		}

		for (int i = 0; i < 5; i++) {
			cout << "\t";
			for (int j = 0; j < 5; j++) {
				cout << ranks[i][j] << "\t\t";
			}
			cout << "|\t" << cars[i] << endl;
		}
		cout << endl << endl;
		in.close();
		return **ranks;
	}
	else
	{
		cout << "Файл не знайдено.";
		return **ranks;
	}
}

double multiplying(double weight[5], int ranks[5][5], double mult[5][5], char cars[5]) {

	cout << endl << endl << "Перемножаємо бали з вагами, де 'Е' - максимальне для кожного параметру:\n\n";
	for (int i = 0; i < 5; i++) {
		cout << cars[i] << "\t | \t";
		for (int j = 0; j < 5; j++) {
			mult[i][j] = weight[j] * ranks[i][j];
			cout << mult[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-----------------------------------------------------" << endl;
	return **mult;
}

double param_max(double mult[5][5]) {
	double max[5] = { 0,0,0,0,0 };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (max[j] < mult[i][j]) {
				max[j] = mult[i][j];
			}
		}
	}
	cout << "E\t | \t";
	for (int i = 0; i < 5; i++) {
		cout << max[i] << "\t";
	}
	cout << endl << endl;
	return 0;
}

double result(double mult[5][5], char cars[5]) {
	double sum[5] = { 0,0,0,0,0 };
	double max = 0;

	cout << "\n\nСума 'ваг' параметрiв для кожного об'єкту:" << endl << endl;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			sum[i] = sum[i] + mult[i][j];
		}
		cout << sum[i] << "\t";
	}
	cout << endl << "-------------------------------------" << endl;

	for (int i = 0; i < 5; i++) {
		cout << cars[i] << "\t";
	}

	cout << endl << endl;
	for (int i = 0; i < 5; i++) {
		if (max < sum[i]) {
			max = sum[i];
		}
	}
	cout << "\nНайбiльша сума 'ваг' параметрiв об'єктiв становить - " << max << endl << endl << endl;
	return 0;
}

void main() {
	setlocale(LC_ALL, "Ukrainian");
	double weight[5];
	int ranks[5][5];
	double mult[5][5];
	char cars[5] = { 'A', 'Б' ,'В' , 'Г' , 'Д' };

	cout << "Розгiн до 100км/год\tЗаряд батареi\t\tДальнiсть\tПотужнiсть\t\tЦiна\n";

	read_file_w(weight);
	read_file_r(ranks, cars);
	multiplying(weight, ranks, mult, cars);
	param_max(mult);
	result(mult, cars);

	system("pause");
}