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

void print_named_mtrx(Mtrx& current, std::string mtrx_name)
{
	system("cls");
	std::cout << "Итоговая матрица " << mtrx_name << ":\n";
	current.print_mtrx();
}

void fill_mtrx_console_input(Mtrx &current, std::string mtrx_name)
{
	int y_size, x_size;
	std::vector<float> mtrx_values;
	current.clear_current_mtrx();
	tie(y_size, x_size, mtrx_values) = console_input();
	current.init(mtrx_values, y_size, x_size);
	print_named_mtrx(current,mtrx_name);
}

void fill_mtrx_file_input(Mtrx &current,std::string mtrx_name)
{
	std::cout << "Введите путь: ";
	std::string path;
	std::cin >> path;
	int y_size, x_size;
	std::vector<float> mtrx_values;
	current.clear_current_mtrx();
	tie(y_size, x_size, mtrx_values) = file_input(path);
	current.init(mtrx_values, y_size, x_size);
	print_named_mtrx(current, mtrx_name);
}

void functions_menu(Mtrx &A,Mtrx &B)
{
	system("cls");
	std::vector<std::string> func_menu = { "Список действий\n1.A+B\n2.A+=B\n3.A-B(-3 - для B-A)\n"
		"4.A-=B\n5.A*B\n6.A+value\n7.B+value\n8.A*value\n9.B*value\n10.A/value\n11.B/value"
		"12.A^value\n13.B^value\n14.det(A)\n15.det(B)\n16.Норма матрицы A\n17.Норма матрицы B\n"};
	std::cout << func_menu[0];
	int choice = 0;
	while (true)
	{
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Mtrx C = A + B;
			print_named_mtrx(C, "C");
			break;
		}
		case 2:
		{
			A += B;
			print_named_mtrx(A, "A");
			break;
		}
		case -2:
		{
			B += A;
			print_named_mtrx(A, "A");
			break;
		}
		case 3:
		{
			Mtrx C = A - B;
			print_named_mtrx(C, "C");
			break;
		}
		case -3:
		{
			Mtrx C = B - A;
			print_named_mtrx(C, "C");
			break;
		}
		case 4:
		{
			A -= B;
			print_named_mtrx(A, "A");
			break;
		}
		case -4:
		{
			B -= A;
			print_named_mtrx(B, "B");
			break;
		}
		case 5:
		{
			Mtrx C= A* B;
			print_named_mtrx(C, "C");
			break;
		}
		case -5:
		{
			Mtrx C = B * A;
			print_named_mtrx(C, "C");
			break;
		}
		case 6:
		{
			float value;
			std::cout << "Введите число: ";
			std::cin >> value;
			A += value;
			print_named_mtrx(A, "A");
			break;
		}
		case 7:
		{
			float value;
			std::cout << "Введите число: ";
			std::cin >> value;
			B += value;
			print_named_mtrx(B, "B");
			break;
		}
		case 8:
		{
			float value;
			std::cout << "Введите число: ";
			std::cin >> value;
			A *= value;
			print_named_mtrx(A, "A");
			break;
		}
		case 9:
		{
			float value;
			std::cout << "Введите число: ";
			std::cin >> value;
			B *= value;
			print_named_mtrx(B, "B");
			break;
		}
		case 10:
		{
			float value;
			std::cout << "Введите число: ";
			std::cin >> value;
			A /= value;
			print_named_mtrx(A, "A");
			break;
		}
		case 11:
		{
			float value;
			std::cout << "Введите число: ";
			std::cin >> value;
			B /= value;
			print_named_mtrx(B, "B");
			break;
		}
		case 12:
		{
			int value;
			std::cout << "Введите степень: ";
			std::cin >> value;
			A ^= value;
			print_named_mtrx(A, "A");
			break;
		}
		case 13:
		{
			int value;
			std::cout << "Введите степень: ";
			std::cin >> value;
			B ^= value;
			print_named_mtrx(B, "B");
			break;
		}
		case 14:
		{
			system("cls");
			std::cout << "det(A) = " << A.determinant()<<"\n";
			break;
		}
		case 15:
		{
			system("cls");
			std::cout << "det(B) = " << B.determinant()<<"\n";
			break;
		}
		case 16:
		{
			system("cls");
			std::cout << "K-norm: " << A.K_normal_mtrx() << "\n";
			std::cout << "L-norm: " << A.L_normal_mtrx() << "\n";
			std::cout << "M-norm: " << A.M_normal_mtrx() << "\n";
			break;
		}
		case 17:
		{
			system("cls");
			std::cout << "K-norm: " << B.K_normal_mtrx() << "\n";
			std::cout << "L-norm: " << B.L_normal_mtrx() << "\n";
			std::cout << "M-norm: " << B.M_normal_mtrx() << "\n";
			break;
		}
		default:
			break;
		}
		std::cout << func_menu[0];
	}
}

void main_menu(Mtrx &A,Mtrx&B) 
{
	setup_console();
	std::vector<vector<std::string>> menu = {
	{"1.Ввод матрицы A.\n2.Ввод матрицы B.\n3.Переход к выбору действия.\n4.Выход.\n"},
	{"1.Ввод с консоли.\n2.Ввод из файла.\n","Введите путь: "}
	};
	std::cout << menu[0][0];
	int choice = 0, second_choice=0;
	int x_size, y_size;
	while (true)
	{
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			std::cout << menu[1][0];
			std::cin >> second_choice;
			switch (second_choice)
			{
			case 1:
			{
				fill_mtrx_console_input(A,"A");
				break;
			}
			case 2:
			{
				fill_mtrx_file_input(A,"A");
			}
			default:
				break;
			}
			break;
		};
		case 2:
		{
			std::cout << menu[1][0];
			std::cin >> second_choice;
			switch (second_choice)
			{
			case 1:
			{
				fill_mtrx_console_input(B,"B");
				break;
			}
			case 2:
			{
				fill_mtrx_file_input(B,"B");
				break;
			}
			default:
				break;
			}
			break;
		};
		case 3:
			functions_menu(A,B);
		case 4:
			return;
		default:
			break;
		}
		std::cout<<menu[0][0];
	}
	
}

void main_menu_utility()
{
	Mtrx A, B;
	main_menu(A, B);
}

int main()
{
	main_menu_utility();
	//D:\\university\\Lab1.7.2_2sem_PPOIS_proj\\Sources\\1.txt
	return 0;
}