/*!
\file
\brief ������������ ���� � ��������� ������.

������ ���� �������� � ���� ����������� ������ � �������� ������� ������, ������������ � ���������.
*/
#pragma once
#include <iostream>
#include <vector>
using std::vector;
/*!
\brief ����� ������������ �������

������ ����� �������� ������ �� ��������, ���������, ���������, ������� ������, ����� ���������� ����������� �
���� �������.
*/
class Mtrx
{
private: 
	vector<vector<float>> mtrx;
	float determinant_utility(vector<vector<float>>& mtrx, int mtrx_size);
	void subMatrix(vector<vector<float>>& mtrx, vector<vector<float>>& temp, int p, int q, int n);
	int get_y_size();
	int get_x_size();
	float get_elm_by_index(int x_index, int y_index);
	void set_elm_by_index(int& x_index, int& y_index, float& elm);
	vector<vector<float>> get_current_mtrx();
	vector<float> get_line_by_index(int y_index);
	vector<float> get_column_by_index(int x_index);
public:
	/// <summary>
	/// ����� ������������ ��� ������������� �������.
	/// </summary>
	/// <param name="input_values">������ ������������ ����� ��� ���������� �������.</param>
	/// <param name="size_y">���������� ����� �������.</param>
	/// <param name="size_x">���������� �������� �������.</param>
	void init(const vector<float>& input_values, const int& size_y, const int& size_x);
	/// <summary>
	/// ����� ������� �� �����.
	/// </summary>
	void print_mtrx();
	/// <summary>
	/// ������� ������� �������.
	/// </summary>
	void clear_current_mtrx();
	/// <summary>
	/// ���������� ���������(+). ���������� �������� �������� 2�� ������.
	/// ����������� ���������� ������ ����� ������ ������ Mtrx, ������� �(���������). 
	/// </summary>
	/// <param name="right">�������� � �����, ������ ������� ��� ���������� �������� ��������. </param>
	/// <returns>Mtrx sum_res</returns>
	const Mtrx operator+(Mtrx& right);
	/// <summary>
	/// ���������� ���������(+=). ���������� �������� �������� 2�� ������.
	/// ��������� ��������� ������������ � ������� �������.  
	/// </summary>
	/// <param name="right">�������� � �����, ������ ������� ��� ���������� �������� ��������.</param>
	const void operator+=(Mtrx& right);
	/// <summary>
	/// ���������� ���������(-). ���������� �������� ��������� 2�� ������.
	/// ����������� ���������� ������ ����� ������ ������ Mtrx, ������� �(���������). 
	/// </summary>
	/// <param name="right">�������� � �����, ������ ������� ��� ���������� �������� ���������.</param>
	/// <returns>Mtrx difference_res</returns>
	const Mtrx operator-(Mtrx& right);
	/// <summary>
	/// ���������� ���������(-=). ���������� �������� ��������� 2�� ������.
	/// ��������� ��������� ������������ � ������� �������.  
	/// </summary>
	/// <param name="right">�������� � �����, ������ ������� ��� ���������� �������� ���������.</param>
	const void operator-=(Mtrx& right);
	/// <summary>
	/// ���������� ���������(+). ���������� �������� �������� ������� � ������������� �����.
	/// ����������� ���������� ������ ����� ������ ������ Mtrx, ������� �(���������).
	/// </summary>
	/// <param name="addition_value">�������� � �����,������������� ����� ��� ���������� �������� ��������.</param>
	/// <returns>Mtrx addition_res</returns>
	const Mtrx operator+(float addition_value);
	/// <summary>
	/// ���������� ���������(+). ���������� �������� �������� ������� � ������������� �����.
	/// ��������� ��������� ������������ � ������� �������.  
	/// </summary>
	/// <param name="addition_value">�������� � �����,������������� ����� ��� ���������� �������� ��������.</param>
	const void operator+=(float addition_value);
	/// <summary>
	/// ���������� ���������(-). ���������� ��������� ��������� �� ������� ������������� �����.
	/// ����������� ���������� ������ ����� ������ ������ Mtrx, ������� �(���������). 
	/// </summary>
	/// <param name="difference_value">�������� � �����,������������� ����� ��� ���������� �������� ���������</param>
	/// <returns>Mtrx difference_res</returns>
	const Mtrx operator-(float difference_value);
	/// <summary>
	/// ���������� ���������(-=). ���������� ��������� �������� ������� � ������������� �����.
	/// ��������� ��������� ������������ � ������� �������.  
	/// </summary>
	/// <param name="difference_value">�������� � �����,������������� ����� ��� ���������� �������� ���������</param>
	const void operator-=(float difference_value);
	bool check_multiplication_possibility(Mtrx& right);
	/// <summary>
	/// ���������� ���������(*). ���������� �������� ��������� 2�� ������.
	/// ����������� ���������� ������ ����� ������ ������ Mtrx, ������� �(���������). 
	/// </summary>
	/// <param name="right">�������� � �����, ������ ������� ��� ���������� �������� ������������. </param>
	/// <returns>Mtrx multiplication_res</returns>
	const Mtrx operator*(Mtrx& right);
	/// <summary>
	/// ���������� ���������(*). ���������� �������� ��������� ������� �� ������������ �����.
	/// ����������� ���������� ������ ����� ������ ������ Mtrx, ������� �(���������). 
	/// </summary>
	/// <param name="multiplication_value">�������� � �����,������������� ����� ��� ���������� �������� ������������.</param>
	/// <returns>Mtrx multiplication_res</returns>
	const Mtrx operator*(float multiplication_value);
	/// <summary>
	/// ���������� ���������(*=). ���������� �������� �������� ������� � ������������� �����.
	/// ��������� ��������� ������������ � ������� �������.  
	/// </summary>
	/// <param name="multiplication_value">�������� � �����,������������� ����� ��� ���������� �������� ������������.</param>
	const void operator*=(float multiplication_value);
	/// <summary>
	/// ���������� ���������(/). ���������� �������� ������� ������� �� ������������ �����.
	/// ����������� ���������� ������ ����� ������ ������ Mtrx, ������� �(���������).
	/// </summary>
	/// <param name="division_value">�������� � �����,������������� ����� ��� ���������� �������� �������.</param>
	/// <returns>Mtrx division_res</returns>
	const Mtrx operator/(float division_value);
	/// <summary>
	/// ���������� ���������(/=). ���������� �������� �������� ������� � ������������� �����.
	/// ��������� ��������� ������������ � ������� �������.  
	/// </summary>
	/// <param name="division_value">�������� � �����,������������� ����� ��� ���������� �������� �������.</param>
	const void operator/=(float division_value);
	/// <summary>
	/// ���������� ���������(^). ���������� �������� ���������� � ������� �������.
	/// ����������� ���������� ������ ����� ������ ������ Mtrx, ������� �(���������).
	/// </summary>
	/// <param name="involution_value">�������� � �����,������ ����� ��� ���������� �������� ���������� � �������</param>
	/// <returns>Mtrx res_mtrx</returns>
	const Mtrx operator^(int involution_value);
	/// <summary>
	/// ���������� ���������(^=). ���������� �������� ���������� � ������� �������.
	/// ��������� ��������� ������������ � ������� �������.  
	/// </summary>
	/// <param name="involution_value">�������� � �����,������������� ����� ��� ���������� �������� ���������� � �������.</param>
	const void operator^=(int involution_value);
	/// <summary>
	/// ����� �� ���������� ������������(������������) �������.
	/// ����������� ������ ������������ �����.
	/// </summary>
	/// <returns>float determinant</returns>
	float determinant();
	/// <summary>
	/// ����� �� ���������� M-����� �������.
	/// ����������� ������ ������������ �����.
	/// </summary>
	/// <returns>float M_norm</returns>
	float M_normal_mtrx();
	/// <summary>
	/// ����� �� ���������� L-����� �������.
	/// ����������� ������ ������������ �����.
	/// </summary>
	/// <returns>float L_norm</returns>
	float L_normal_mtrx();
	/// <summary>
	/// ����� �� ���������� K-����� �������.
	/// ����������� ������ ������������ �����.
	/// </summary>
	/// <returns>float K_norm</returns>
	float K_normal_mtrx();
};