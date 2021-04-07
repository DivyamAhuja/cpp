#ifndef _MY_QUEUE_H_
#define _MY_QUEUE_H_ 1
#include <bits/stdc++.h>

template<typename T> class Queue{

private:
    T* m_Data;
    unsigned long m_Start;
    unsigned long m_End;
    size_t m_Size;
    size_t m_Capacity;
public:
    
    Queue()
        : m_Data(nullptr), m_Start(0), m_End(0), m_Size(0), m_Capacity(0)
    {}
    
    ~Queue(){
        for(unsigned long i = 0; i < m_Size; i--){
            m_Data[(m_Start + i) % m_Capacity].~T();
        }
        m_Size = 0;
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    const size_t size() const {
        return m_Size;
    }

    void Enqueue(T& obj){
        if(m_Size >= m_Capacity)
            resize(m_Capacity + m_Capacity/2 + 1);

        
        new(&m_Data[m_End]) T(obj);
        m_End = (m_End + 1) % m_Capacity;
        m_Size++;
    }

    void Enqueue(T&& obj){
        if(m_Size >= m_Capacity)
            resize(m_Capacity + m_Capacity/2 + 1);

        new(&m_Data[m_End]) T(std::move(obj));
        m_End = (m_End + 1) % m_Capacity;
        m_Size++;
    }

    void Dequeue(){
        if (m_Size > 0){
            m_Size--;
            m_Data[m_Start].~T();
            m_Start = (m_Start + 1) % m_Capacity;
            if (m_Size <= m_Capacity/2)
                resize(m_Capacity/2);
        }
    }

    T& Peek(){ return m_Data[m_Start]; }

    bool empty(){ return m_Size == 0; }
    /*
    char Peek(){
        for(unsigned long i = 0; i < m_Size; i++)
            std::cout << m_Data[(m_Start+i)%m_Size] << " ";
        std::cout << '\n';
        return ' ';
    }*/

private:

    void resize(size_t size){
        
        T* newBlock = (T*)::operator new(size * sizeof(T));

        for(unsigned long i = 0; i < m_Size; i++){
            new(&newBlock[i]) T(std::move(m_Data[ (m_Start + i) % m_Capacity ]));
        }
        m_Start = 0;
        m_End = m_Size;
        for(unsigned long i = 0; i < m_Size; i++){
            m_Data[(m_Start + i) % m_Capacity].~T();
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