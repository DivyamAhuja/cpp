#ifndef _MY_HEAP_H_
#define _MY_HEAP_H_ 1
#include <iostream>
#include "Vector.h"
template<typename T> class Heap{

private:
    Vector<T> m_Data;
    size_t m_Size = 0;
public:
    Heap(){}

    ~Heap(){}
};

#endif