﻿#include <iostream>

//функция для поиска первого числа в зависимости от разряда числа
int firstnum(int n);

//функция для произведения цифр числа
int proizv(int n);

int main()
{
    int n;
    std::cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    //сортировка по 1 числу
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (firstnum(array[i]) > firstnum(array[j])) {
                std::swap(array[i], array[j]);
            }
        }
    }
    //сортировка по произведению для одинаковых 1 чисел
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (firstnum(array[i]) == firstnum(array[j])) {
                if (proizv(array[i]) < proizv(array[j])) {
                    std::swap(array[i], array[j]);
                }
            }
        }
    }
    //сортировка по одинаковым числам и произведениям
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (firstnum(array[i]) == firstnum(array[j]) && proizv(array[i]) == proizv(array[j])) {
                if (array[i] > array[j]) {
                    std::swap(array[i], array[j]);
                }
            }
        }
    }
    //вывод
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    delete[] array;
    return 0;
}

int proizv(int n) 
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