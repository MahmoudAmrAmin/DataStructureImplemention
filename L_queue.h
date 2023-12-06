//
// Created by mahmod on 12/5/2023.
//
#ifndef DATASTRUCTURES_IMPLEMENT_L_QUEUE_H
#define DATASTRUCTURES_IMPLEMENT_L_QUEUE_H
#include<iostream>
using namespace  std;
template<class t>class linked_queue
{
private:
    struct Node
    {
        t item ;
        Node * next;
    };
    Node * fro ;
    Node * rear ;
    int length ;
public:
    linked_queue();
    void push( t element);
    bool empty();
    void pop();
    t front();
    t back();
    void clear();
    void print();
};

template<class t> bool linked_queue<t>::empty()
{
    return length == 0;
}
template<class t> linked_queue<t>::linked_queue()
{
    rear = fro = NULL;
    length = 0;
}
template<class t> void linked_queue<t>::push(t element)
{
    Node * newNode = new Node ;
    newNode->item = element;
    if(empty())
    {
        fro = rear = newNode ;
        fro ->next = NULL;
        length ++ ;
        return ;
    }
    else
    {
        rear->next = newNode ;
        rear = newNode ;
        rear->next = NULL;
    }
    length ++ ;
}

template<class t> void linked_queue<t>::pop()
{
    if(empty()){cout<<"underflow"<<endl;return ;}
    Node * temp = new Node ;
    temp = fro;
    fro= fro->next;
    delete temp;
    length -- ;


}
template<class t> t linked_queue<t>::front()
{
    if(empty()){cout<<"underflow"<<endl;return -1;}
    return fro->item;
}

template<class t> t linked_queue<t>::back()
{
    if(empty()){cout<<"underflow"<<endl;return -1;}
    return rear->item;
}

template<class t> void linked_queue<t>::clear()
{
    Node * curr = new Node ;
    while(fro!=NULL)
    {
        curr=fro;
        fro = fro->next;
        delete curr;
    }
    rear = NULL;
    length = 0;
}

template<class t>void linked_queue<t>::print()
{
    Node * curr  = new Node;
    curr = fro;
    while ( curr != NULL)
    {
        cout<<curr->item<<" ";
        curr = curr->next;
    }
}
#endif //DATASTRUCTURES_IMPLEMENT_L_QUEUE_H
