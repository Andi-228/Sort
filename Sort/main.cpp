#include <iostream>
#include <ctime>

using namespace std;

void printArr(int* arr, int size);
void bubbleSort(int* arr, int size);
void selectionSort(int* arr, int size);
int* makeArr(int size);
void mySwap(int& a, int& b);

int main() {
	srand(time(NULL));
	int size = 10;
	int* arr = makeArr(size);
	cout << "Inintial array: " << endl;
	printArr(arr, size);
	//bubbleSort(arr, size);
	selectionSort(arr, size);
	cout << "Array after sorting: " << endl;
	printArr(arr, size);
	delete arr;

	
	system("pause");
	return 0;
}

void printArr(int* arr, int size)
{ 
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				mySwap(arr[j], arr[j + 1]);
			}
		}
		cout << "________________" << endl;
		printArr(arr, size);
	}
}

void selectionSort(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		int tmp = arr[i];
		int index = i;
		for (int j = i; j < size; j++) {
			if (arr[j] > tmp) {
				tmp = arr[j];
				index = j;
			}
		}
		mySwap(arr[i], arr[index]);
	}
}

int* makeArr(int size)
{
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
	}
	return arr;
}

void mySwap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
