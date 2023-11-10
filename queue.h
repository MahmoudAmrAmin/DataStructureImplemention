//
// Created by mahmod on 11/10/2023.
//

#ifndef DATASTRUCTURES_IMPLEMENT_QUEUE_H
#define DATASTRUCTURES_IMPLEMENT_QUEUE_H
#include<iostream>
using namespace std ;
template<class T >class queue
{
private:
    int fr ,ba,size;
    T * arr;
public:
    queue(int size);
    bool full();
    bool empty();
    void push ( T item);
    void pop();
    void pop(T & item);
    T front();
    T back();
    void PrintAllElement();
    void reverse();
};
template<class t > queue<t> ::queue(int size)
{
    fr = -1  , ba = -1 ;
    this ->size  =size;
    arr =new int [this->size];
}
template<class t > bool queue<t> ::full()
{
    return  ba ==size-1;
}
template<class t > bool queue<t> ::empty() {
    return ((fr == -1 && ba == -1) || (fr > ba));
}
template <class t > void queue<t>::push(t item)
{
    if(full()){cout<<"overflow , queue is full"<<endl;return;}
    if(fr==-1){++fr;}
    ++ba;
    arr[ba]=item;
}

template<class t>void queue<t>::pop(){
    if(empty()){cout<<"underflow , queue is empty"<<endl; return;}
    ++fr;
}

template<class t> void queue<t>::pop(t &item)
{
    if(empty()){cout<<"underflow , queue is empty"<<endl; return;}
    item = arr [fr];
    ++fr;
}

template<class t> t queue<t>::front()
{
    if(empty()){cout<<"underflow , queue is empty"<<endl; return -1;}
    return arr[fr];
}

template<class t> t queue<t>::back()
{
    if(empty()){cout<<"underflow , queue is empty"<<endl; return -1 ;}
    return arr [ba];
}

template<class t>void queue<t>::PrintAllElement()
{
    for (int i = fr; i <=ba ; ++i) {
        cout<<arr[i]<<" ";
    }
}

template<class t>void  queue<t>::reverse()
{
    t temp [size];
    for (int i = ba; i>=fr ; --i) {
        temp[i]=arr[i];
    }
    int j =ba;
    for (int i = fr; i <=ba ; ++i) {
        arr[i]=temp[j];
        j--;
    }
}

#endif //DATASTRUCTURES_IMPLEMENT_QUEUE_H
