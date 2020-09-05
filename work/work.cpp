#include<iostream>
#include<ctime>
#include <cstdlib>

using namespace std;

void FillArray(int*& arr, int& size) {
	for (int i = 0; i < size; i++)
	{
		
		arr[i] = rand() % 10;
	}
}

void ShowArray(int*& arr, int& size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void pushTop(int*& arr, int& size, int value, int k) {
	size++;
	int* newArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (i == k)
		{
			newArray[i] = value;
			continue;
		}
		if (i < k)
		{
			newArray[i] = arr[i];
		}
		if (i > k)
		{
			newArray[i] = arr[i - 1];
		}
	}
	delete[] arr;
	arr = newArray;
}

void popTop(int*& arr, int& size, int k) {
	size--;
	int* newArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (i == k)
		{
			newArray[i] = arr[i + 1];
		}
		if (i > k)
		{
			newArray[i] = arr[i + 1];
			continue;
		}
		if (i < k)
		{
		newArray[i] = arr[i];
		}
		
	}
	delete[] arr;
	arr = newArray;
}

int IfTrue(int &k) {
	cout << "Enter value before " << 10 << ":";
	cin >> k;
	if (k <= 10){
		return k;
	}
	return IfTrue(k);
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int size = 10;
	int* arr = new int[size];
	int value;
	cout << "Enter value: ";
	cin >> value;
	int k; // На какую позицию ставить элемент?
	cout << "Where to put the value: ";
	cin >> k;
	if (k > size)
	{
		IfTrue(k);
	}
	
	FillArray(arr, size);
	cout << "Array0 = ";
	ShowArray(arr, size);
	cout << endl;
	cout << "Array+ = ";
	pushTop(arr, size, value, k);
	ShowArray(arr, size);
	cout << endl;
	cout << "Array- = ";
	popTop(arr, size, k);
	ShowArray(arr, size);
	cout << endl;
	delete[] arr;
	system("pause");
}