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


};

bool check_mtrx_multiplication_possibility(Mtrx&left,Mtrx &right)
{
	if (left.get_y_size() == right.get_x_size())
		return true;
	else
		return false;
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
	if (check_mtrx_multiplication_possibility(left, right))
	{
		Mtrx result_mtrx;
		vector<float> result_values;
		
	}
	else
		std::cout << "Operation impossible!";
}

int main()
{
	vector<float> test = { 2,3,4,5,1,2,3,4,5,6,7,8 };
	Mtrx m;
	m.init(test, 4, 3);
	Mtrx m1;
	m1.init(test, 4, 3);
	m.print_mtrx();
	std::cout << std::endl;
	m -= 1000;
	m.print_mtrx();
	std::cout << std::endl;
	return 0;
}