#include <iostream>
#include "sparse_matrix.h"

int main(int, char**)
{

    otus::SparseMatrix<int> matrix;
    constexpr int size = 10;

    for (int i = 0, j = size-1; i < size; ++i, j = size-1-i)
    {
        matrix[i][i] = i;
        matrix[i][j] = j;
    }

    for(int i = 1; i < size-1; ++i)
    {
        for(int j = 1; j < size-1; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    std::cout << "full max count matrix: " << matrix.size() << std::endl;

    for(const auto& [s ,b] : matrix)
    {
        std::cout <<"Row: "<<s[0]<<" Column: " << s[1] << " Value: "<< b << std::endl;
    }
    
    matrix.clear();

    ((matrix[100][100] = 314) = 0) = 217;

    std::cout << "Size: "<< matrix.size() <<" Value: "<< matrix[100][100]<< std::endl;
    
    matrix.clear();
    
    for(int i = 0; i < size; ++i)
        matrix[i][i][i] = i;
    
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
             for(int k = 0; k < size; ++k)
             {
                 std::cout << matrix[i][j][k] << " ";
             }
            std::cout << std::endl;    
        }
        std::cout << std::endl;
    }
    std::cout << "Size: "<< matrix.size() << std::endl;
}

