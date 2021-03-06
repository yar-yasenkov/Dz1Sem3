#ifndef stack_cpp
#define stack_cpp
#pragma once 
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class stack
{
public:
    stack();
    stack(const stack &);
    stack& operator= (const stack &);
    size_t count() const;
    void push(T const &item);
    T pop();
    bool empty_() const;
    ~stack();
    
private:
    
    T * array_;
    size_t array_size_;
    size_t count_;
    void grow();
    
    
};
template <typename T>
stack<T>::stack() : array_size_(0), count_(0), array_(nullptr) {};
template <typename T>
stack<T>::~stack() { delete[] array_; }
template <typename T>
size_t  stack<T>::count() const { return count_; };
template <typename T>
void stack<T>::push(T const &item)
{
    if (array_size_ <= count_) { grow(); }
    array_[count_++] = item;
}

template<typename T>
T stack<T>::pop() {
    if (empty_()) {
        throw std::logic_error("Stack is empty!");
    }
    return array_[--count_];
    
}
template <typename T>
void stack<T>::grow() {
    size_t new_array_size_=0;
    if (array_size_ == 0) new_array_size_=1;
    if (array_size_ <= count_) new_array_size_= new_array_size_*2;
    T *new_array_ = new T[new_array_size_];
    copy(array_, array_ + count_, new_array_);
    if (!empty_()) {
        delete[] array_;
    }
    array_ = new_array_;
    array_size_ = new_array_size_;
    return;
}
template <typename T>
bool stack<T>::empty_() const {
    return count_ == 0;
}
template <typename T>
stack<T>& stack<T>::operator=(const stack<T> &tmp) {
    count_ = tmp.count_;
    array_size_ = tmp.array_size_;
    array_ = new T[array_size_];
    copy(tmp, tmp + count_, array_);
    return *this;
}
template <typename T>
stack<T>::stack(const stack &tmp)
: count_(tmp.count_),
array_size_(tmp.array_size_)
{
    array_ = new T[array_size_];
    copy(tmp, tmp + count_, array_);
}

#endif
