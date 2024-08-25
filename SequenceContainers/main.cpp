﻿#include<iostream>
#include<array>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------\n"

//#define STL_ARRAY
#define STL_VECTOR

template<typename T> void vector_properties(const std::vector<T>& vec);

void main()
{
	setlocale(LC_ALL, "Rus ");
#ifdef STL_ARRAY
	//array - контейнер, который хранит  данные в виде статического массива.
	const int SIZE = 5;
	std::array<int, SIZE> arr = { 3, 5, 8 };
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - контейнер который хранит данные в виде динамического массива.
	std::vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec.at(i) << tab;
			//cout << vec[i] << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	vector_properties(vec);

	vec.push_back(144);
	vector_properties(vec);

	//vec.resize(15); // задаёт фактический размер Вектора.
	vec.shrink_to_fit(); //урезает вместительность до фактического размера.
	vec.reserve(120);   // резервирует память до нужного объёма памяти до 120, метод выполняется 
	//если мы передаём значение больше текущего capacity().
	for (int i : vec)cout << i << tab; cout << endl;
	vector_properties(vec);
	cout << vec.front() << endl;
	cout << vec.back() << endl;
	cout << vec.data() << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << *(vec.data() + i) << tab;
		//cout << vec.data()[i] << tab;
	}
	cout << endl;
	cout << "Iterators:" << endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
	int index; int value;
	while (index < 0 || index >= vec.size()) {
		cout << "Неверный индекс. Пожалуйста, введите число от 0 до " << vec.size() << ": ";
		cin >> index;
	}
	cout << endl;
	cout << "Введите добавляемое значение: "; cin >> value;
	/*auto iter = vec.cbegin();
	vec.insert(index, value);
	auto begin = vec.cbegin();
	auto end = vec.cend();
	vec.erase(begin+index-8);
	std::erase(vec, index);*/

#endif // STL_VECTOR
}
template<typename T> void vector_properties(const std::vector<T>& vec)
{
	cout << "SIZE:\t" << vec.size() << endl;
	cout << "CAPACITY:" << vec.capacity() << endl;
	cout << "MAX_SIZE:" << vec.max_size() << endl;
	cout << delimiter << endl;
}