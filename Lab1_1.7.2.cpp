#include <iostream>
#include <vector>
using std::vector;

class Mtrx
{
private:
	vector<vector<float>> mtrx;
public:

	void init(const vector<float>& input_values, const int& size_x, const int& size_y)
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

	float get_elm_by_index(int& x_index, int& y_index)
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

int check_mtrx_multiplication_possibility(Mtrx&left,Mtrx &right)
{
	if (left.get_y_size() == right.get_x_size())
		return 1;
	else if (left.get_x_size() == right.get_y_size())
		return 2;
	else
		return 0;
}

const Mtrx operator+(Mtrx& left, Mtrx& right)
{
	Mtrx result_mtrx;
	vector<float> result_values;
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			result_values.push_back(left.get_elm_by_index(x, y) + right.get_elm_by_index(x, y));
		}
	result_mtrx.init(result_values, left.get_x_size(), right.get_y_size());
	return result_mtrx;
}

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

const Mtrx operator-(Mtrx& left, Mtrx& right)
{
	Mtrx result_mtrx;
	vector<float> result_values;
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			result_values.push_back(left.get_elm_by_index(x, y) - right.get_elm_by_index(x, y));
		}
	result_mtrx.init(result_values, left.get_x_size(), right.get_y_size());
	return result_mtrx;
}

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

const Mtrx operator+(Mtrx& left, float addition_value)
{
	Mtrx result_mtrx;
	vector<float> result_values;
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			result_values.push_back(left.get_elm_by_index(x, y) + addition_value);
		}
	result_mtrx.init(result_values, left.get_x_size(), left.get_y_size());
	return result_mtrx;
}

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

const Mtrx operator-(Mtrx& left, float difference_value)
{
	Mtrx result_mtrx;
	vector<float> result_values;
	for (int y = 0; y < left.get_y_size(); ++y)
		for (int x = 0; x < left.get_x_size(); ++x)
		{
			result_values.push_back(left.get_elm_by_index(x, y) - difference_value);
		}
	result_mtrx.init(result_values, left.get_x_size(), left.get_y_size());
	return result_mtrx;
}

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

const Mtrx operator*(Mtrx&left,Mtrx&right)
{
	if(check_mtrx_multiplication_possibility(left,right)==2)
		std::swap(left, right);
	Mtrx result_mtrx;
	vector<float> result_values;
	vector <float> tmp_line, tmp_column;
	float result_value = 0;
	for (int y = 0; y < left.get_x_size(); ++y) {
			for (int x = 0; x < right.get_y_size(); ++x)
			{
				tmp_line = left.get_line_by_index(y);
				tmp_column = right.get_column_by_index(x);
				for (int j = 0; j < tmp_line.size(); ++j)
				{
					if (j > tmp_column.size()-1 && j > tmp_line.size()-1)
						break;
					result_value += tmp_line[j] * tmp_column[j];
				}
				result_values.push_back(result_value);
				result_value = 0;
			}
		}
	result_mtrx.init(result_values, left.get_x_size(),right.get_y_size() );
	return result_mtrx;
}

int main()
{
	vector<float> test = {1,2,3,4,9,10,11,3};
	vector<float> test1 = {1,8,10,12,34,2,11,93,45,11,34,100};
	Mtrx m;
	m.init(test, 4, 2);
	Mtrx m1;
	m1.init(test1, 3, 4);
	m.print_mtrx();
	std::cout << std::endl;
	m1.print_mtrx();
	std::cout << std::endl;
	Mtrx m2;
	m2 = m * m1;
	m2.print_mtrx();
	std::cout << std::endl;
	return 0;
}