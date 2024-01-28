//
// Created by mahmod on 10/31/2023.
//

#ifndef DATASTRUCTURES_IMPLEMENT_STACK_H
#define DATASTRUCTURES_IMPLEMENT_STACK_H
#include<iostream>
#include<algorithm>
using namespace std ;
// stack array based

int MAX_SIZE =100;
template<class t>class stack
{
private:

    int count;
    int top ;
    int siz;
public:

    t * item ;
    stack(int size);
    stack();
    ~stack();
    bool empty();
    bool full ();
    void push(t element);
    void pop(t & Deleted );
    void pop();
    void print();
    t Top();
    int size();
    void swap(stack<t> & s);
    void reSize();
};

template<class t> stack<t>::stack(int si)
{
    if(si < 0)
    {
        siz = MAX_SIZE ;
    }
    else{this -> siz = si;}
    top = -1 ;
    item = new t [ siz] ;
    count = 0;
}
template<class t> stack<t>::stack()
{
    siz = MAX_SIZE ;
    top = -1 ;
    item = new t [siz] ;
    count = 0 ;
}

template<class t> bool stack<t>::empty()
{
    return count == 0 ;
}

template<class t> bool stack<t>::full()
{
    return count == (siz  );
}

template<class t> void stack<t>::push(t element)
{
    if(size() == siz){reSize();}
    item [++ top ]= element ;
    count ++ ;
}

template<class t> void stack<t>::pop(t &Deleted)
{
    if(empty()){cout<<"stack already is empty"<<endl;return ; }
    Deleted = item[top -- ];
    count --;
}
template<class t> void stack<t>::pop()
{
    if(empty()){cout<<"stack already is empty"<<endl;return ; }
    top -- ;
    count -- ;
}

template<class t> void stack<t>::print()
{
    if (empty()){cout<<"stack already is empty"<<endl;return ;}
    int i = top ;
    i++;
    while(i--)
    {
        cout<<item [i]<<endl;
    }
}

template<class t> stack<t>::~stack()
{
    delete item ;
}

template<class t>t stack<t>::Top()
{
    if(empty()){cout<<"stack already is empty"<<endl;return -1 ;}
    return item[top];
}

template<class t>int stack<t>::size()
{
    if(empty()){return 0 ;}
    return count ;
}

template<class t>void stack<t>::reSize()
{
    siz = (siz == 0) ? 1 : 2 * siz ;
    t * newItem = new t [siz];
    for (int i = 0; i < size(); ++i) {
        newItem[i]=item[i];
    }
    delete item ;
    item = newItem;
}

template<class t>void stack<t>::swap(stack<t> &s)
{
    if(s.size() == 0 || size() == 0){cout<<"invalid swap operation "<<endl;return ; }
    int i = size() , j = s.size() ;
    while(i >=0 && j >=0 )
    {
        t temp = s.item[j];
        s.item[j]=item[i];
        item[i]=temp;
        i-- , j-- ;
    }
}
#endif //DATASTRUCTURES_IMPLEMENT_STACK_H
