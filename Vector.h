#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_ 1
#include <iostream>

template<typename T>
void LOG(T x){
    std::cout<< x <<'\n';
} 

template<typename T> class Vector{

private:
    T* m_Data;
    size_t m_Size;
    size_t m_Capacity;

    void ReAlloc(size_t newCapacity){
        size_t oldSize = m_Size;
        if (newCapacity < m_Size)
            m_Size = newCapacity;

        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));
        
        for(unsigned long i = 0; i < m_Size; i++){
            //newBlock[i] = std::move(m_Data[i]);
            new(&newBlock[i]) T(std::move(m_Data[i]));
        }
        
        for(unsigned long i = 0; i < oldSize; i++){
            m_Data[i].~T();
        }

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;
        m_Capacity = newCapacity;
        
    }

public:
    Vector()
        : m_Data(nullptr), m_Size(0), m_Capacity(0) {
            ReAlloc(1);
        }

    ~Vector(){
        clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));    
    }

    T& operator[] (unsigned long int i){return m_Data[i];}
    const T& operator[] (unsigned long int i) const {return m_Data[i];} 
    
    void print(){
        std::cout << " --- ";
        for(unsigned long i = 0; i < m_Size; i++){
            std::cout << m_Data[i] << " ";
        }
        std::cout << '\n';
    }

    void reserve(size_t size){
        ReAlloc(size);
    }

    void shrink_to_fit(){
        if(m_Capacity == m_Size)
            return;
        ReAlloc(m_Size);
    }

    const size_t capacity() const {
        return m_Capacity;
    }

    const size_t size() const {
        return m_Size;
    }

    void push_back(const T& obj){
        
        if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity/2 + 1);

        new(&m_Data[m_Size]) T(obj);
        m_Size++;
    }

    void push_back(T&& obj){
        
        if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity/2 + 1);

        new(&m_Data[m_Size]) T(std::move(obj));
        m_Size++;
    }

    void pop_back(){
        if(m_Size > 0){
            m_Size--;
            m_Data[m_Size].~T();
        }
    }

    void clear(){
        for(unsigned long i = 0; i < m_Size; i++){
            m_Data[i].~T();
        }
        m_Size = 0;
    }

    template<typename... Args>
    T& EmplaceBack(Args&&... args){
        if(m_Size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity/2 + 1);
        
        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);
        return m_Data[m_Size++];
    }

    T& first(){ return m_Data[0]; }
    const T& first() const{ return m_Data[0]; }
    
    T& back(){ return m_Data[m_Size - 1]; }
    const T& back() const { return m_Data[m_Size - 1]; }
    
};

#endif