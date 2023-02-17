/*
Задача 3. Счётчик чисел
В этом задании вам нужно реализовать функтор,
который подсчитывает сумму и количество чисел, делящихся на 3.

Должны быть реализованы 2 функции:
get_sum()
get_count()
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v = {4, 1, 3, 6, 25, 54};

class functor
{
public:
	functor() : counter(0), sum(0) {}
	int get_count() 
	{
		return counter;
	}
	int get_sum() 
	{
		return sum;
	}
	void operator()(int x) 
	{
		if (x % 3 == 0)
		{
			sum += x;
			counter++;
		}
	}
protected:
	int counter;
	int sum;
};


functor func;

int main()
{
	std::cout << "[IN]: ";
	for (auto i : v)
	{
		std::cout << i << (i == v.back() ? '\n' : ' ');
	}

	func = std::for_each(v.begin(), v.end(), func);
	std::cout << "[OUT]: get_sum() = " << func.get_sum() << '\n';
	std::cout << "[OUT]: get_count() = " << func.get_count() << '\n';
	
	return 0;
}

