#ifndef _MY_LIST_H_
#define _MY_LIST_H_ 1
#include <iostream>

template<typename T> class List{
    struct ListNode{
        T data;
        ListNode* prev;
        ListNode* next;
    };
private:
    ListNode* start;
    ListNode* end;
    size_t m_Size;
public:
    List()
        : start(nullptr), end(nullptr), m_Size(0)
    {}

    ~List(){}

    void push_front(const T& obj){
        ListNode* temp = (ListNode*)::operator new(sizeof(ListNode));
        new(&(temp->data)) T(obj);
        
        temp->prev = nullptr;
        temp->next = start;
        
        if(start != nullptr)
            start->prev = temp;
        else
            end = temp;
        
        start = temp;
        m_Size++;
    }

    void push_front(T&& obj){
        ListNode* temp = (ListNode*)::operator new(sizeof(ListNode));
        new(&(temp->data)) T(std::move(obj));
        
        temp->prev = nullptr;
        temp->next = start;
        
        if(start != nullptr)
            start->prev = temp;
        else
            end = temp;
        
        start = temp;
        m_Size++;
    }

    void pop_front(){
        if(m_Size > 0){
            ListNode* temp = start;
            start = start->next;
            
            if (m_Size > 1)
                start->prev = nullptr;
            else
                end = nullptr;
            
            temp->next = nullptr;
            (temp->data).~T();
            ::operator delete(temp, sizeof(ListNode));

            m_Size--;
        }
    }

    void push_back(const T& obj){
        ListNode* temp = operator new(sizeof(ListNode));
        new(&(temp->data)) T(obj);

        temp->prev = end;
        temp->next = nullptr;

        if(end != nullptr)
            end->next = temp;
        else
            start = temp;
        
        end = temp;
        m_Size++;
    }

    void push_back(T&& obj){
        ListNode* temp = (ListNode*)::operator new(sizeof(ListNode));
        new(&(temp->data)) T(std::move(obj));

        temp->prev = end;
        temp->next = nullptr;

        if(end != nullptr)
            end->next = temp;
        else
            start = temp;

        end = temp;
        m_Size++;
    }

    void pop_back(){
        if(m_Size > 0){
            ListNode* temp = end;
            end = end-> prev;
            temp->prev = nullptr;

            if(end != nullptr)
                end->next = nullptr;

            (temp->data).~T();
            ::operator delete(temp, sizeof(ListNode));

            m_Size--;
        }
    }
    
    void insert(unsigned long index, T& obj){
        if(index == 0){
            push_front(obj);
        }
        else {
            
            ListNode* it = start;
            if(index < m_Size){
                for(int i = 0; i < index - 1; i++)
                    it = it->next;
            }else{
                it = end;
            }

            ListNode* temp = (ListNode*)::operator new(sizeof(ListNode));
            new(&(temp->data)) T(obj);

            temp->prev = it;
            temp->next = it->next;
            
            if(it == end)
                end = temp;

            if(it->next != nullptr)
                it->next->prev = temp;
            it->next = temp;

            m_Size++;
        }
    }

    void insert(unsigned long index, T&& obj){
        if(index == 0){
            push_front(std::move(obj));
        }
        else {

            ListNode* it = start;
            if(index < m_Size){
                for(int i = 0; i < index - 1; i++)
                    it = it->next;
            }else{
                it = end;
            }

            ListNode* temp = (ListNode*)::operator new(sizeof(ListNode));
            new(&(temp->data)) T(std::move(obj));

            temp->prev = it;
            temp->next = it->next;
            
            if(it == end)
                end = temp;

            if(it->next != nullptr)
                it->next->prev = temp;
            it->next = temp;

            m_Size++;
        }
    }

    void remove(){

    }

    T& front() { return start->data; }
    const T& front() const { return start->data; }
    
    T& back() { return end->data; }
    const T& back() const { return end->data; }

private:

};
#endif