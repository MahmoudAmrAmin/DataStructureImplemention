
#ifndef DATASTRUCTURES_IMPLEMENT_STACK_H
#define DATASTRUCTURES_IMPLEMENT_STACK_H
#include<iostream>
using namespace std;
#define Endl endl;
const int Max_size = 100 ;
template <class t > class Stack{
    t top;
    t item [Max_size];
public :
    Stack()
    {
        top = -1 ;
    }
    void push (t element)
    {
        if(top >= INT_MAX-1)
        {
            cout<<"stack.h overflow "<<endl;
        }
        else
        {
            top++;
            item[top ]=element;
        }
    }
    bool isempty()
    {
        return top < 0 ;
    }
    void pop()
    {
        if(isempty()){cout<<" underflow"<<Endl;}
        else {top -- ;}
    }
    void pop (t &  element)   //call by ref
    {
        if( isempty() )
        {
            cout<<"underflow"<<endl;
        }
        else
        {
            element = item [top];
            top--;
        }
    }
    void getTop(t &GetTop)
    {
        if(isempty())
        {
            cout<<"underflow"<<endl;

        }
        else
        {
            GetTop=  item[top];
        }
    }
    void print()
    {
        cout<<"[ ";
        for (int  i = top ; i >= 0  ;i --) {
            cout<<item[i]<<" ";
        }
        cout<<"] "<<Endl;
    }
};
#endif //DATASTRUCTURES_IMPLEMENT_STACK_H
//
// Created by mahmod on 10/24/2023.
//
#include <iostream>
#include<vector>
using namespace  std;

#ifndef DS_IMPLEMENTATION_STACK_H
#define DS_IMPLEMENTATION_STACK_H

template <class t> class stack{
private:
    int max_size ;
    t * items ;
    int top ;
public:
    stack(int max_size)
    {
        this -> max_size = max_size;
        top = - 1 ;
        items =new  t [max_size];
    }
    ~stack()
    {
        delete items;
        items = NULL ;
        top = -1 ;
        max_size = 0;
    }
    void push(t item )
    {
        if(full())
        {
            cout<<"overflow"<<endl;
            return;
        }
        top++;
        items[top] = item;
    }
    bool full ()
    {
        return top == max_size-1;
    }
    bool empty()
    {
        return top == -1;
    }
    void pop()
    {
        if(empty()){
            cout<<"underflow"<<endl;
            return;
        }
        top--;
    }
    t  Top()
    {
        if(empty()){cout<<"underflow"<<endl;return -1;}
        return items[top];
    }
    void print_all_element()
    {
        cout<<"stack : | ";
        for (int i = top; i >=0 ; --i) {
            cout<<items[top]<<" ";
        }
    }
};

#endif //DS_IMPLEMENTATION_STACK_H