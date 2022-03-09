#include <iostream>
#include "sparse_matrix.h"

int main(int, char**)
{

    otus::SparseMatrix<int> test;

    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            test[i][j] = j;
        }
    }
       

    for(auto [s ,b] : test)
    {
        std::cout <<s[0] << s[1] << b << std::endl;
    }

    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            std::cout << test[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}