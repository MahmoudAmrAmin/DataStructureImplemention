//
// Created by mahmod on 10/24/2023.
//
#include <iostream>
using namespace  std;

#ifndef DS_IMPLEMENTATION_LSTACK_H
#define DS_IMPLEMENTATION_LSTACK_H
template<class t >class Stack
{
private:
    struct node
    {
        t item;
        node * next;
    };
    node * top;
public:
    Stack(){top= NULL ; }
    void push(t ele)
    {
      node * newptr =new node;
      if(newptr == NULL ){cout<<"Stack push can't allocated memory "<<endl;}
      else {
          newptr->item = ele;
          newptr->next = top;
          top = newptr;
      }
    }
    bool empty()
    {
        return top == NULL;
    }
    void pop(t & ele)
    {
        if(empty()){cout<<"underflow"<<endl;}
        else
        {
            ele =top ->item;
            node * temp = new node;
            temp = top ;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }
    void getTop(t & ele)
    {
        if(empty()){cout<<"underflow"<<endl;}
        else
        {
            ele =top ->item;
        }
    }
    void display()
    {
        node * cur = top;
        while(cur !=   NULL)
        {
            cout<<cur ->item <<" " ;
            cur = cur->next;
        }
    }
};
#endif //DS_IMPLEMENTATION_LSTACK_H
