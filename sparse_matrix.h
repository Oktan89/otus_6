/**
 * @file sparse_matrix.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <vector>
#include <ostream>
#include <map>




namespace otus
{
    template <typename T, T _default = T{}>
    class SparseMatrix
    {
    private:
        class MatrixProxy
        {
        public:
             using maptrix_type = std::map<std::vector<std::size_t>, T>;
        private:
            std::vector<std::size_t> _index;
            maptrix_type matrix;
            
            friend SparseMatrix;
        public:
           
            MatrixProxy()
            {
                _index.reserve(4);
            }

            MatrixProxy &operator[](std::size_t index)
            {
                set(index);
                return *this;
            }

            void set(std::size_t index)
            {
                _index.push_back(index);
            }

            MatrixProxy &operator=(const T& value)
            {
                if(value == _default)
                {
                    auto index = matrix.find(_index);
                    if(index != matrix.end())
                        matrix.erase(index);
                }
                else
                { 
                    matrix[_index] = value;
                }

                return *this;
            }

            void resetIndex()
            {
                _index.clear();
            }

            operator T()
            {
                auto d = matrix.find(_index);
                if(d != matrix.end())
                    return d->second;
                else
                    return _default; 
            }

            friend std::ostream &operator<<(std::ostream &out, const MatrixProxy &_matrix)
            {
                auto d = _matrix.matrix.find(_matrix._index);
                if (d != _matrix.matrix.end())
                    out << d->second;
                else
                    out << _default;
                return out;
            }
        };

    public:
        SparseMatrix() {}

        MatrixProxy &operator[](std::size_t index)
        {
            proxy.resetIndex();
            proxy.set(index);
            return proxy;
        }

        typename MatrixProxy::maptrix_type::size_type size() const noexcept
        {
            return proxy.matrix.size();
        }

        auto begin()
        {
            return proxy.matrix.begin();
        }

        auto end()
        {
            return proxy.matrix.end();
        }

        void clear()
        {
            proxy.matrix.clear();
        }

    private:
        MatrixProxy proxy;
    };

}