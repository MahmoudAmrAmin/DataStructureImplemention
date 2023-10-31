#include<iostream>
#include "stack.h"
#include<string>
using namespace std;
#define Endl endl;
// infix to postfix function // important



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
int GetOperatorWight(char op )
{
    int wight = -1 ;
    switch(op)
    {
        case '+':
        case '-':
            wight = 1;break;
        case'*':
        case'/':
            wight=2;
        case '$':
            wight=3;
    }
    return wight;
}
int HasHeightPrecedence(char op1 ,char op2)
{
    int wight1= GetOperatorWight(op1);
    int wight2= GetOperatorWight(op2);
    if(wight1 == wight2)
    {
        if(IsRightAcc(op1)){return false;}
        return true;
    }
    return wight1 > wight2;
}
string infixToPostfix(string expression) {
    Stack<char> s;
    string postFix = "";
    for (int i = 0; i < expression.size(); ++i) {
        if (expression[i] == ' ' || expression[i] == ',') { continue; }
        else if (IsOperator(expression[i])) {
            while (!s.isempty() && s.getTop() != '(' && HasHeightPrecedence(s.getTop(), expression[i])) {
                postFix += s.getTop();
                s.pop();
            }
            s.push(expression[i]);
        } else if (IsOperand(expression[i])) {
            postFix += expression[i];
        } else if (expression[i] == '(') {
            s.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!s.isempty() && s.getTop() != '(') {
                postFix += s.getTop();
                s.pop();
            }
            s.pop();
        }

    }
    while (!s.isempty()) {
        postFix += s.getTop();
        s.pop();
    }
    s.pop();
    return postFix;
}
int main()
{
cout<<infixToPostfix("5+5");

}