#pragma once
#include <vector>
#include <ostream>
#include <map>


class SparseMatrix
{
private:

    class MatrixRow
    {
        std::vector<int> _index;
        std::map<std::vector<int>, int> column;
    public:
        MatrixRow() {}

        MatrixRow& operator[](int col)
        {   
            set(col);
            return *this;
        }
        void set(int index)
        {
            _index.push_back(index);
        }

        MatrixRow& operator=(int value)
        {
            column[_index] = value;
            return *this;
        }

        void reset()
        {
            _index.clear();
        }

        friend std::ostream& operator<<(std::ostream& out, const MatrixRow& matrix)
        {   auto d = matrix.column.find(matrix._index);
            if(d != matrix.column.end())
                out << d->second << std::endl;
            else
                out << 0 << std::endl;
            return out;
        }

    };

public:
    SparseMatrix(){}
  
    MatrixRow& operator[](int _row)
    {
        test.reset();
        test.set(_row);
        return test;
    }

private:
MatrixRow test;

};


