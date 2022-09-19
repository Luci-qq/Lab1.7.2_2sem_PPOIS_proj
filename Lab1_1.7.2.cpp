#include <iostream>
#include <vector>
using std::vector;

//main Mtrx class
class Mtrx
{
private:
	vector<vector<float>> mtrx;
public:

	void init(const vector<float>& input_values, const int& size_y, const int& size_x)
	{
		vector<float> tmp_vector;
		tmp_vector.resize(size_x);
		for (size_t y = 0; y < size_y; ++y)
			mtrx.push_back(tmp_vector);
		int current_index = 0;
		for (size_t y = 0; y < size_y; ++y)
			for (size_t x = 0; x < size_x; ++x)
			{
				mtrx[y][x] = input_values[current_index];
				current_index++;
			}
		return;
	}

	void print_mtrx()
	{
		for (int y = 0; y < mtrx.size(); ++y)
		{
			for (int x = 0; x < mtrx[y].size(); ++x)
			{
				std::cout << mtrx[y][x] << "  ";
			}
			std::cout << std::endl;
		}
	}

	int get_y_size()
	{
		return mtrx.size();
	}

	int get_x_size()
	{
		return mtrx[0].size();
	}

	float get_elm_by_index(int x_index, int y_index)
	{
		return mtrx[y_index][x_index];
	}

	void set_elm_by_index(int& x_index, int& y_index, float& elm)
	{
		mtrx[y_index][x_index] = elm;
		return;
	}

	vector<float> get_line_by_index(int y_index)
	{
		return mtrx[y_index];
	}

	vector<float> get_column_by_index(int x_index)
	{
		vector<float> column;
		for (int y = 0; y < get_y_size(); ++y)
		{
			column.push_back(mtrx[y][x_index]);
		}
		return column;
	}

};

//mtrx sum+
const Mtrx operator+(Mtrx& left, Mtrx& right)
{
	Mtrx sum_res;
	vector<float> result_values;
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			result_values.push_back(left.get_elm_by_index(x, y) + right.get_elm_by_index(x, y));
		}
	sum_res.init(result_values, left.get_x_size(), right.get_y_size());
	return sum_res;
}
//mtrx sum+=
const void operator+=(Mtrx& left, Mtrx& right)
{
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			float set_elm = left.get_elm_by_index(x, y) + right.get_elm_by_index(x, y);
			left.set_elm_by_index(x, y, set_elm);
		}
	return;
}
//mtrx difference-
const Mtrx operator-(Mtrx& left, Mtrx& right)
{
	Mtrx difference_res;
	vector<float> result_values;
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			result_values.push_back(left.get_elm_by_index(x, y) - right.get_elm_by_index(x, y));
		}
	difference_res.init(result_values, left.get_x_size(), right.get_y_size());
	return difference_res;
}
//mtrx difference-=
const void operator-=(Mtrx& left, Mtrx& right)
{
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			float set_elm = left.get_elm_by_index(x, y) - right.get_elm_by_index(x, y);
			left.set_elm_by_index(x, y, set_elm);
		}
	return;
}
//mtrx sum+(number)
const Mtrx operator+(Mtrx& left, float addition_value)
{
	Mtrx sum_res;
	vector<float> result_values;
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			result_values.push_back(left.get_elm_by_index(x, y) + addition_value);
		}
	sum_res.init(result_values, left.get_x_size(), left.get_y_size());
	return sum_res;
}
//mtrx sum+=(number)
const void operator+=(Mtrx& left, float addition_value)
{
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			float set_elm = left.get_elm_by_index(x, y) + addition_value;
			left.set_elm_by_index(x, y, set_elm);
		}
	return;
}
//mtrx difference-(number)
const Mtrx operator-(Mtrx& left, float difference_value)
{
	Mtrx difference_res;
	vector<float> result_values;
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			result_values.push_back(left.get_elm_by_index(x, y) - difference_value);
		}
	difference_res.init(result_values, left.get_x_size(), left.get_y_size());
	return difference_res;
}
//mtrx difference-=(number)
const void operator-=(Mtrx& left, float addition_value)
{
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			float set_elm = left.get_elm_by_index(x, y) - addition_value;
			left.set_elm_by_index(x, y, set_elm);
		}
	return;
}
//check mtrx rows and columns(possibility for multiplying)
bool check_multiplication_possibility(Mtrx &left, Mtrx &right)
{
	if (left.get_y_size() == right.get_x_size())
		return true;
	else
		return false;
}
//mtrx multiplication*
const Mtrx operator*(Mtrx&left,Mtrx&right)
{
	Mtrx multiplication_res;
	float tmp_res = 0;
	vector<float> result_values;
	vector<vector<float>> tmp_left_mtrx;
	vector<vector<float>> tmp_right_mtrx;
	for (int y = 0; y < left.get_y_size(); ++y)
		tmp_left_mtrx.push_back(left.get_line_by_index(y));
	for (int x = 0; x < right.get_x_size(); ++x)
		tmp_right_mtrx.push_back(right.get_column_by_index(x));
	for (int i = 0; i < tmp_left_mtrx.size(); ++i)
	{
		for (int j = 0; j < tmp_right_mtrx.size(); ++j)
		{
			tmp_res = 0;
			for (int z = 0; z < tmp_right_mtrx[j].size(); ++z)
			{
				tmp_res += tmp_left_mtrx[i][z] * tmp_right_mtrx[j][z];
			}
			result_values.push_back(tmp_res);
		}
	}
	multiplication_res.init(result_values, left.get_y_size(), right.get_x_size());
	return multiplication_res;
}
//mtrx multiplication*(number)
const Mtrx operator*(Mtrx& left, float multiplication_value)
{
	Mtrx difference_res;
	vector<float> result_values;
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			result_values.push_back(left.get_elm_by_index(x, y) * multiplication_value);
		}
	difference_res.init(result_values, left.get_x_size(), left.get_y_size());
	return difference_res;
}
//mtrx multiplication*=(number)
const void operator*=(Mtrx&left, float multiplication_value)
{
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			float set_elm = left.get_elm_by_index(x, y) * multiplication_value;
			left.set_elm_by_index(x, y, set_elm);
		}
	return;
}
//mtrx division/(number)
const Mtrx operator/(Mtrx& left, float division_value)
{
	Mtrx difference_res;
	vector<float> result_values;
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			result_values.push_back(left.get_elm_by_index(x, y) / division_value);
		}
	difference_res.init(result_values, left.get_x_size(), left.get_y_size());
	return difference_res;
}
//mtrx multiplication*=(number)
const void operator/=(Mtrx& left, float division_value)
{
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			float set_elm = left.get_elm_by_index(x, y) / division_value;
			left.set_elm_by_index(x, y, set_elm);
		}
	return;
}
//mtrx involution^
const Mtrx operator^(Mtrx&left,int involution_value)
{
	Mtrx res_mtrx;
	Mtrx tmp_mtrx = left;
	for (int i = 1; i < involution_value; ++i)
	{
		res_mtrx = tmp_mtrx * left;
		tmp_mtrx = res_mtrx;
	}
	return res_mtrx;
}
//mtrx involution^=
const void operator^=(Mtrx& left, int involution_value)
{
	Mtrx res_mtrx;
	Mtrx tmp_mtrx = left;
	for (int i = 1; i < involution_value; ++i)
	{
		res_mtrx = tmp_mtrx * left;
		tmp_mtrx = res_mtrx;
	}
	left = res_mtrx;
}
//mtrx determinate
int determinant(Mtrx&left) {
	int det = 0;
	int submatrix[10][10];
	if (left.get_x_size() == 2 && left.get_y_size() == 2)
		return ((left.get_elm_by_index(0,0) * left.get_elm_by_index(1,1)) - (left.get_elm_by_index(1,0) * left.get_elm_by_index(0,1)));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
		}
	}
	return det;
}
int main()
{
	vector<float> test = {4,5,10};
	vector<float> test1 = {1,2,3,4,5,6,7,8,9};
	Mtrx m;
	m.init(test1, 3,3);
	m^=5;
	m.print_mtrx();
	std::cout << std::endl;
	return 0;
}