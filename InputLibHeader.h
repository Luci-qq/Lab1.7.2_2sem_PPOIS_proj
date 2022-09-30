/*!
\file
\brief ������������ ���� � ��������� ������� �����.

������ ���� �������� � ���� ����������� �������� �������, ������������ ��� ����� ������ � ���������.
*/
#pragma once
#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>
#include <fstream>
/// <summary>
/// ����� ��� ������ ������ �� �����.
/// ����������� �������� 2 ����� �������������� ����� ������� �������(���������� �����, ���������� ��������) � 
/// ������ ������������ �����(�������� ��� ���������� �������). 
/// </summary>
/// <param name="path">���� � ����� ����������� ����������.</param>
/// <returns>tuple<int,int,std::vector<float>></returns>
std::tuple<int, int, std::vector<float>> file_input(std::string& path);
/// <summary>
/// ����� ��� �������� ������ �� �������(���������).
/// ����������� �������� 2 ����� �������������� ����� ������� �������(���������� �����, ���������� ��������) � 
/// ������ ������������ �����(�������� ��� ���������� �������). 
/// </summary>
/// <returns>tuple<int,int,std::vector<float>></returns>
std::tuple<int, int, std::vector<float>> console_input();