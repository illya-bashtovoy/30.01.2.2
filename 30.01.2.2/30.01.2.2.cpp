/*
Завдання 2.Написати функцію, яка отримує покажчик на  динамічний масив і його розмір.
Функція має видалити з масиву всі прості числа та повернути покажчик на новий динамічний масив
*/

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cmath>

using namespace std;

void fillingArr(int* arr, int size);
void dellArr(const int* arr, const int size);
bool primeNumber(int n);
void checkDell(const int* arr, int* nArr, const int size);

int main() {
    srand(time(NULL));
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    int size = 1, count = 1;

    cout << "Введіть розмір size елементів  масиву = ";
    cin >> size;

    int* arr = new int[size];
    int* nArr = new int[count];

    fillingArr(arr, size);
    cout << "Елементи масиву" << endl;
    dellArr(arr, size);
    cout << "Елементи нового масиву які не містять простих чисел" << endl;
    checkDell(arr, nArr, size); 
   
    delete[]arr;
    delete[]nArr;
}


void fillingArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 + 1;
    }
}


void dellArr(const int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "]=" << " " << arr[i] << endl;
    }
}


bool primeNumber(int n) {
    bool result(true);

    if ((n == 2) or (n == 3))
        result = true;

    else {
        for (int i = 2; i <= floor(sqrt(n)); ++i)
            if (n % i == 0) {
                result = false;
                break;
            }
    }

    return (result and (n != 1));
}


void checkDell(const int* arr, int* nArr, const int size) {
    int count = 0;

    for (int i = 0; i < size; ++i) {
        if (!primeNumber(arr[i]))
            ++count; 
    }

    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (!primeNumber(arr[i]))
            nArr[j++] = arr[i];
    }

    for (int j = 0; j < count; j++)
        cout << "newArr [" << j << "] =" << " " << nArr[j] << endl;
}