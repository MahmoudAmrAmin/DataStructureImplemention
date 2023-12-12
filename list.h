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
    t front();
    t back();
    bool empty();
    void push_front(t element);
    void push_back(t element);
    void insertAtPosition(t pos , t element);
    void pop_front();
    void pop_back();
    void print();
    int size ();
    void removeByValue(t element);
};

template<class t> int linked_list<t>::size()
{
    return count;
}
template<class t> linked_list<t>::linked_list()
{
    count = 0 ;
    head = last = NULL;
}

template<class t> bool linked_list<t>::empty()
{
    return count <=0;
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

template<class t> void linked_list<t>::pop_front() {
    if(empty())
    {
        cout<<"underflow , list is empty "<<endl;
    }
    else if(size() == 1)
    {
        head = last =NULL;
        count--;
    }
    else
    {
        node * temp = new node ;
        temp = head ;
        head = head->next ;
        delete temp ;
        count -- ;
    }

}
template<class t> t linked_list<t> ::front()
{
    if(empty())
    {
        cout<<"underflow , list is empty"<<endl;
        return -1 ;
    }
    return head ->item;
}

template<class t> void linked_list<t>::pop_back()
{
    if(empty())
    {
        cout<<"underflow , list is empty "<<endl;
    }
    else if(size() == 1)
    {
        head = last =NULL;
        count--;
    }
    else
    {
        node * curr  = new node, * temp = new node;
        temp = head->next;
        curr = head ;
        while(temp != last)
        {
            curr = temp;
            temp= temp->next ;
        }
        last = curr ;last ->next = NULL ;
        delete temp , curr;

        count --;
    }
}

template<class t> t linked_list<t> ::back()
{
    if(empty())
    {
        cout<<"underflow , list is empty"<<endl;
        return -1 ;
    }
    return last ->item;
}

template<class t> void linked_list<t>::removeByValue(t element)
{
    if(empty())
    {
        cout<<"underflow"<<endl;return ;
    }
    node * curr = new node , * pre = new node;
    if(head ->item == element)
    {
        curr = head ;
        pre = head ->next ;
        head = pre ;
        delete curr ;
        count -- ;
        if( ! count ){last = NULL ; }
    }
    else
    {
        curr = head ;
        pre = head -> next ;
        while(curr != NULL )
        {
            if(curr ->item == element){break;}
             pre = curr ;
            curr = curr->next  ;
        }
        if(curr == NULL){cout<<"element not found"<<endl;return;}
        else
        {
            pre->next = curr ->next ;
            if(last == curr){
                last = pre;
                delete curr;
                count --;
            }
        }

    }
}
#endif //DATASTRUCTURES_IMPLEMENT_LIST_H
