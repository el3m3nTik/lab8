#include <iostream>

int main()
{
    int row, col;
    int sum = 10000, index = 0;
    std::cin >> row; // строки
    std::cin >> col; // столбцы
    int** mtrx = new int* [row];
    for (int i = 0; i < col; i++)
    {
        mtrx[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            int mat;
            std::cin >> mat;
            mtrx[i][j] = mat;
        }
    }
    for (int i = 0, temp = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            temp += mtrx[j][i];
            if (temp < sum) {
                sum = temp;
                index = i;
            }
        }
        temp = 0;
    }
    for (int i = 0; i < col; i++) {
        mtrx[i][index] *= 3;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << mtrx[i][j];
            std::cout << " ";
        }
        std::cout << "\n";
    }
    for (int i = 0; i < row; i++) {
        delete[] mtrx[i];
    }

    delete[] mtrx;
    return 0;
}