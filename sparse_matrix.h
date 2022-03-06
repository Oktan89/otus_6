#pragma once
#include <vector>

class SparseMatrix
{
private:

    class MatrixRow
    {
        std::vector<int> col;
    public:
        MatrixRow() : col(10)
        {
             for(int i = 0; i < 10; ++i)
                col[i] = i * 2;   
        }
        int& operator[](int row)
        {
            return col[row];
        }
    };

public:
    SparseMatrix() : row(10)
    {

    }
    MatrixRow& operator[](int _row)
    {
          return row[_row];
    }

private:
std::vector<MatrixRow> row;
    
};

