#include <iostream>
#include "sparse_matrix.h"

int main(int, char**)
{

    SparseMatrix test;

    test[0][9] = 123;
    std::cout << test[0][9] << std::endl;
}