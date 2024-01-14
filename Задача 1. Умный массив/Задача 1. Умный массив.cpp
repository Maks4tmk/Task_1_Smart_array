// Задача 1. Умный массив.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class smart_array
{
public:
	smart_array(int size);
	~smart_array();

	void add_element(int value) {
		if (count >= size)
		{
			throw std::out_of_range("Новый элемент выходит за пределы массива!");
		}
		else {
			arr[count] = value;
			count++;
		}
	}

	int get_element(int index) {
		if (index < 0 || !(index < size)) {
			throw std::out_of_range("Индекс находится за пределами массива!");
		}
		else { return arr[index]; }
	}

private:
	int size = 0;
	int *arr = 0;
	int count = 0;
};

smart_array::smart_array(int size)
{
	this->size = size;
	arr = new int[size] {};
}

smart_array::~smart_array()
{
	delete[] arr;
}


int main()
{
	setlocale(LC_ALL,"ru");

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(2) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}


