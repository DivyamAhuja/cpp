#ifndef _MY_DICTIONARY_H_
#define _MY_DICTIONARY_H_ 1
#include <iostream>

template<typename TypeKey, typename TypeValue,class Hash = std::hash<TypeKey>> class Dictionary{

private:
    

    
public:

    Dictionary(){}

    ~Dictionary(){}

    TypeValue& operator[] (TypeKey&& key){
        
    }
};

#endif