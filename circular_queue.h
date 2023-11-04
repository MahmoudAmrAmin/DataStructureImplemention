<<<<<<< HEAD
//
// Created by mahmod on 11/4/2023.
//

#ifndef DATASTRUCTURES_IMPLEMENT_QUEUE_H
#define DATASTRUCTURES_IMPLEMENT_QUEUE_H
#include<iostream>
using namespace std;
template<class T>class queue
{
    
};

#endif //DATASTRUCTURES_IMPLEMENT_QUEUE_H
=======
//
// Created by mahmod on 11/4/2023.
//

#ifndef DATASTRUCTURES_IMPLEMENT_CIRCULAR_QUEUE_H
#define DATASTRUCTURES_IMPLEMENT_CIRCULAR_QUEUE_H
#include<iostream>
#include<cassert>
using namespace std;
template<class T>class circular_queue
{
private:
    int fr , ba , count , size ; // count : to count element
    T  * arr ;
public:
    circular_queue(int size);
    bool empty();
    bool full();
    void push(T element);
    void pop();
    T front();
    T back();
    void display();
};
template<class T> circular_queue<T> ::circular_queue(int size )
{
    if(size<=0){ this->size = 100;}
    else
        this -> size =size;
    fr = 0 ; ba= this->size-1;
    arr = new T [this->size];
}
template<class T>
bool circular_queue<T>::empty() {
   return count == 0;
}
template<class T>
bool circular_queue<T>::full()
{
    return count == size ;
}
template<class T>
void circular_queue<T>::push(T element)
{
    if(full()){cout<<"overflow"<<endl;}
    else
    {

        ba = (ba+1)%size;
        arr[ba]=element;
        count ++ ;
    }
}
template<class T>
void circular_queue<T>::
pop()
{
    if(empty()){cout<<"underflow"<<endl;}
    else
    {
        fr = (fr+1)%size;
        count--;
    }
}
template<class T>
T circular_queue<T>::front()
{
    assert(!empty());
    return arr [fr];
}
template<class T>
T circular_queue<T>::back()
{
    assert(!empty());
    return arr [ba];
}
template<class T> void circular_queue<T>::display() {
    int i = fr;
    for(;i!= ba;i=(i+1)%size)
    {
        cout<<arr[i]<<" ";
    }
    cout<<arr[ba];

}

#endif //DATASTRUCTURES_IMPLEMENT_CIRCULAR_QUEUE_H
>>>>>>> origin/main
