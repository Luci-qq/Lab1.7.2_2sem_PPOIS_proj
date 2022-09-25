#include <iostream>
#include <vector>
#include "MtrxHeader.h"
#include "InputLibHeader.h"
using std::vector;

void setup_console()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
}

void main_menu() 
{
	setup_console();
	vector<vector<std::string>> menu = {
	{"1.Ввод матрицы A.\n2.Ввод матрицы B.\n3.Переход к выбору действия.\n4.Выход.\n"},
	{"1.Ввод с консоли.\n2.Ввод из файла.\n"},
	{"Количество строк матрицы: ", "Количество столбцов матрицы: ", "Введите элементы матрицы:\n", "Итоговая матрица: \n"},
	{"Введите путь к файлу: "}
	};
	std::cout << menu[0][0];
	int choice = 0;
	std::cin >> choice;
	while (true)
	{
		switch (choice)
		{
		case 1:
		{

		};
		default:
			break;
		}
	}
	//functions_menu();
}


int main()
{
	int x, y;
	vector<float> inpur;
	std::string path="D:\\university\\Lab1.7.2_2sem_PPOIS_proj\\Sources\\1.txt";
	tie(y,x,inpur)=file_input(path);
	return 0;
}