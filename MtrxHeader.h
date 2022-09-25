#pragma once
#include <iostream>
#include <vector>
using std::vector;

class Mtrx
{
private: 
	vector<vector<float>> mtrx;
	float determinant_utility(vector<vector<float>>& mtrx, int mtrx_size);
	void subMatrix(vector<vector<float>>& mtrx, vector<vector<float>>& temp, int p, int q, int n);
public:
	void init(const vector<float>& input_values, const int& size_y, const int& size_x);
	void clear_current_mtrx();
	void print_mtrx();
	int get_y_size();
	int get_x_size();
	float get_elm_by_index(int x_index, int y_index);
	void set_elm_by_index(int& x_index, int& y_index, float& elm);
	vector<vector<float>> get_current_mtrx();
	vector<float> get_line_by_index(int y_index);
	vector<float> get_column_by_index(int x_index);
	const Mtrx operator+(Mtrx& right);
	const void operator+=(Mtrx& right);
	const Mtrx operator-(Mtrx& right);
	const void operator-=(Mtrx& right);
	const Mtrx operator+(float addition_value);
	const void operator+=(float addition_value);
	const Mtrx operator-(float difference_value);
	const void operator-=(float difference_value);
	bool check_multiplication_possibility(Mtrx& right);
	const Mtrx operator*(Mtrx& right);
	const Mtrx operator*(float multiplication_value);
	const void operator*=(float multiplication_value);
	const Mtrx operator/(float division_value);
	const void operator/=(float division_value);
	const Mtrx operator^(int involution_value);
	const void operator^=(int involution_value);
	float determinant();
	float M_normal_mtrx();
	float L_normal_mtrx();
	float K_normal_mtrx();
};