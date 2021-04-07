#ifndef _MY_STACK_H_
#define _MY_STACK_H_ 1
#include <bits/stdc++.h>

template<typename T> class Stack{

private:
    T* m_Data;
    size_t m_Size;
    size_t m_Capacity;
public:
    
    Stack()
        : m_Data(nullptr), m_Size(0), m_Capacity(0)
    {}
    
    ~Stack(){
        for(unsigned long i = m_Size; i > 0; i--){
            m_Size--;
            m_Data[m_Size].~T();
        }
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    const size_t size() const {
        return m_Size;
    }

    void Push(T& obj){
        if(m_Size >= m_Capacity)
            resize(m_Capacity + m_Capacity/2 + 1);

        new(&m_Data[m_Size]) T(obj);
        m_Size++;
    }
    
    void Push(T&& obj){
        if(m_Size >= m_Capacity)
            resize(m_Capacity + m_Capacity/2 + 1);

        new(&m_Data[m_Size]) T(std::move(obj));
        m_Size++;
    }

    void Pop(){
        if (m_Size > 0){
            m_Size--;
            m_Data[m_Size].~T();

            if (m_Size <= m_Capacity/2)
                resize(m_Capacity/2);
        }
    }

    T& Peek(){ return m_Data[m_Size - 1]; }

    bool empty(){
        return m_Size == 0;
    }
private:

    void resize(size_t size){
        
        T* newBlock = (T*)::operator new(size * sizeof(T));

        for(unsigned long i = 0; i < m_Size; i++){
            new(&newBlock[i]) T(std::move(m_Data[i]));
        }
        for(unsigned long i = 0; i < m_Size; i++){
            m_Data[i].~T();
        }
        ::operator delete(m_Data, m_Size * sizeof(T));
        
        m_Data = newBlock;
        m_Capacity = size;
    }

    const size_t capacity() const {
        return m_Capacity;
    }
};

#endif