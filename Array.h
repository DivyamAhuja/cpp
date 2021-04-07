#include <iostream>

template<typename T, size_t S> class Array{
private:
    T m_Data[S];
public:
    
    Array(){
        memset(m_Data, '\0', S * sizeof(T));
    }

    T& operator[](unsigned long int i){ return m_Data[i]; }
    const T& operator[](unsigned long int i) const { return m_Data[i]; }

    T* data(){ return m_Data; }
    constexpr T* data() const { return m_Data; }

    constexpr size_t size() const{ return S; }

    void printArray(){
        for(unsigned long int i = 0; i < S; i++)
            std::cout << m_Data[i] << " ";
        std::cout << '\n';
    }
};