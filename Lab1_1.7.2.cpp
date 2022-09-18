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

//mtrx sum
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
//mtrx difference
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
//mtrx sum with number
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
//mtrx difference by number
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
//mtrx multiplication
const Mtrx operator*(Mtrx&left,Mtrx&right)
{
	Mtrx multiplication_res;
	vector<float> result_values;
	float tmp_res=0;
	int r1, c1, r2, c2;
	if (left.get_x_size() > right.get_x_size())
		c1 = left.get_x_size();
	else
		c1 = right.get_x_size();
	if (right.get_y_size() > left.get_y_size())
		r1 = right.get_y_size();
	else
		r1 = left.get_y_size();
	for (int i = 0; i < c1; ++i)
		for (int j = 0; j < r1; ++j)
			for (int k = 0; k < c1; ++k)
			{
				result_values.push_back(left.get_elm_by_index(i,k) * right.get_elm_by_index(k,j));
			}
	multiplication_res.init(result_values, left.get_x_size(), right.get_y_size());
	return multiplication_res;
}

int main()
{
	vector<float> test = {1,2,3,4,5,6};
	vector<float> test1 = {1,8,10,12,12,15};
	Mtrx m;
	m.init(test, 2, 3);
	Mtrx m1;
	m1.init(test1, 3,2);
	m.print_mtrx();
	std::cout << std::endl;
	m1.print_mtrx();
	std::cout << std::endl;
	Mtrx m2;
	m2 = m1 * m;
	m2.print_mtrx();
	std::cout << std::endl;
	return 0;
}