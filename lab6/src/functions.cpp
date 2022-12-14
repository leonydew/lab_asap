// functions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "head.hpp"

namespace tatata {
    void read(int& n, int& m, int matrix[N][M])
    {
        std::cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                std::cin >> matrix[n][m];
            }
    }

    bool task(int n, int m, int matrix[N][M])
    {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            bool stringSame = true;
            for (int i = 0; j < n - 1; i++) {
                if (matrix[i][j] != matrix[i + 1][j]) {
                    stringSame = false;
                    break;
                }
            }
            if (stringSame) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            return true;
        }
        else {
            return false;
        }

    }

    int maxInMatrix(int n, int m, int matrix[N][M])
    {
        int maxi = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                for (int k = 2; k <= sqrt(matrix[i][j]); k++)
                {
                    if (matrix[i][j] % i == 0)
                        break;
                    else
                        if (maxi < matrix[i][j]) {
                            maxi = matrix[i][j];
                        }
                }
            }
        return maxi;
    }

    void write(int n, int m, int matrix[N][M])
    {
        if (task(n, m, matrix)) {
            int maxi = maxInMatrix(n, m, matrix);
            for (int j = 0; j < m; j++) {
                int mn = INT_MAX;
                int ind_i = 0, ind_j = 0;
                for (int i = 0; i < m; i++) {
                    if (mn > matrix[i][j]) {
                        ind_i = i;
                        ind_j = j;
                        mn = matrix[i][j];
                    }
                }
                matrix[ind_i][ind_j] = maxi;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
        std::cout << std::endl;
    }
}