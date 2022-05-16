#include <iostream>

using namespace std;

template <typename T>
void insert_element(T*& ar, unsigned int& size, T number, unsigned int index);


template <typename T>
void delete_element(T*& ar, int size, int index);

int main()
{
	int index;
	int* ar = new int[5]{ 1,2,3,4,5 };
	unsigned int size = 5;
	// вставляем в середину массива число 10 по индексу 2

	cin >> index;
	insert_element(ar, size, 10, index);

	cout << endl;

	cin >> index;
	delete_element(ar,size,index);
}

template <typename T>
void delete_element(T*&ar,int size,int index)
{
	size--;
	T* br = new int[size - 1];

	for (int i = 0; i < index; i++)
	{
		br[i] = ar[i];
	}
	for (int i = index; i < size; i++)
	{
		br[i] = ar[i + 1];
	}

	delete[] ar;

	ar = br;

	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << ", ";
	}
}

template <typename T>
void insert_element(T*& ar, unsigned int& size, T number, unsigned int index)
{
	size++;
	T* temp = new T[size];



	for (int i = 0; i < size; i++) {

		if (i < index) temp[i] = ar[i];
		else if (i == index) temp[i] = number;
		else temp[i] = ar[i - 1];
	}

	delete[] ar;
	ar = temp;

	for (int i = 0; i < size; i++)
	{
		cout << ar[i] << ", ";
	}
}