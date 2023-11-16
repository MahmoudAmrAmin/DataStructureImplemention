//
// Created by mahmod on 11/13/2023.
//

#ifndef DATASTRUCTURES_IMPLEMENT_LIST_H
#define DATASTRUCTURES_IMPLEMENT_LIST_H
#include<iostream>
using namespace std ;
template<class t>class linked_list
{
private:
    struct node
    {
        t item;
        node * next;
    };
    node * head;
    node *last;
    int count;
public:
    linked_list();
    bool empty();
    void push_front(t element);
    void push_back(t element);
    void insertAtPosition(t pos , t element);
    void print();
};

template<class t> linked_list<t>::linked_list()
{
    count = 0 ;
    head = last = NULL;
}

template<class t> bool linked_list<t>::empty()
{
    return count ==0;
}

template<class t> void linked_list<t>::push_front(t element)
{
    node * newNode = new node;
    newNode -> item = element;
    if(count == 0) {
        head = last=  newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode ->next = head;
        head = newNode;
    }
    count++;
}
template<class t > void linked_list<t>::push_back(t element)
{
    node * newNode = new node;
    newNode -> item = element;
    if(count == 0) {
        head = last=  newNode;
        newNode->next = NULL;
    }
    else
    {
      last->next= newNode;
      last = newNode;
      last->next= NULL;
    }
    count++;
}

template<class t>void linked_list<t>::insertAtPosition(t pos , t element)
{
    node * newNode = new node;
    newNode -> item = element;
    if(pos < 0 || pos > count)
    {
        cout<<"out of range"<<endl;
    }
    else if(pos==0)
    {
        push_front(element);
    }
    else if(pos == count)
    {
        push_back(element);
    }
    else
    {
        node * curr = head ;
        for (int i = 1; i < pos  ; ++i) {
            curr = curr -> next;
        }
        newNode -> next = curr->next;
        curr ->next = newNode;
    }
    count++;
}

template<class t>void linked_list<t>::print()
{
    node * pri = new node ;
    pri = head;
    while(pri != NULL )
    {
        cout<<pri->item<<" ";
        pri = pri->next;
    }
}


#endif //DATASTRUCTURES_IMPLEMENT_LIST_H
