//
// Created by mahmod on 10/31/2023.
//

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
            cout<<"stack2.h overflow "<<endl;
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
    bool IsOperand(char c)
    {
        if(c>='a'&& c<='z'){return true ; }
        else if(c>='0'&&c<='9'){return  true ;}
        else if(c>='A' && c <='Z'){return true;}
        else {return false ;}
    }
    bool IsOperator(char c)
    {
        switch (c)
        {
            case '+':
                return true;break;
            case '-':
                return true;break;
            case '*':
                return true;break;
            case '/':
                return true;break;
            case '^':
                return true;break;
            case '$':
                return true;break;
            default :
                return false;break;
        }
    }
    bool IsRightAcc(char op)
    {
        if(op == '$'){return true;}
        return false;
    }
};
#endif //DATASTRUCTURES_IMPLEMENT_STACK_H
