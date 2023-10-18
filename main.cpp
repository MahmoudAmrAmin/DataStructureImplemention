#include<bits/stdc++.h>
using namespace std;
#define Endl endl;
// DataStructure implementation
// stack implementation
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
                cout<<"stack overflow "<<endl;
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

int main()
{



}