#include <iostream>


int firstnum(int n);

//Функция для произведения цифр числа
int matpr(int n);

int main()
{
    int n;
    std::cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    //Сортировка по 1 числу
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (firstnum(array[i]) > firstnum(array[j])) {
                std::swap(array[i], array[j]);
            }
        }
    }
    //Сортировка по произведению для одинаковых 1 чисел
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (firstnum(array[i]) == firstnum(array[j])) {
                if (matpr(array[i]) < matpr(array[j])) {
                    std::swap(array[i], array[j]);
                }
            }
        }
    }
    //Сортировка по одинаковым числам и произведениям
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (firstnum(array[i]) == firstnum(array[j]) && matpr(array[i]) == matpr(array[j])) {
                if (array[i] > array[j]) {
                    std::swap(array[i], array[j]);
                }
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    delete[] array;
    return 0;
}

int matpr(int n) 
{
    if (n >= 0 && n < 10) {
        return n;
    }
    if (n >= 10 && n < 100) {
        return ((n % 10) * (n / 10));
    }
    if (n >= 100 && n < 1000) {
        return ((n / 100) * ((n / 10) % 10) * (n % 10));
    }
    if (n == 1000) {
        return 1;
    }
}

int firstnum(int n)
{
    if (n >= 0 && n < 10) {
        return n;
    }
    if (n >= 10 && n < 100) {
        return n / 10;
    }
    if (n >= 100 && n < 1000) {
        return n / 100;
    }
    if (n == 1000) {
        return n / 1000;
    }
}