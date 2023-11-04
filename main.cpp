#include<iostream>
#include "stack.h"
#include<string>
#include"circular_queue.h"
using namespace std;
#define Endl endl;
// infix to postfix function // important



/*bool IsOperand(char c)
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
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '^':
            return true;
        default :
            return false;
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
}*/
/*string infixToPostfix(string expression) {
    stack<char> s;
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
}*/
/*int prec(char sy)
{
    switch(sy)
    {
        case '(':
            return 1;
        case ')':
            return 2;
        case '+':
        case '-':
            return 3;
        case '*':
        case '/':
        case '%':
            return 4;
        case'^':
            return 5;
        default :
            return 0 ;
    }
}
string  infixToPostfix(string infix ,string& postfix)
{
    stack<char>s;
    int size = infix.size();
    int priority;// prec

    infix+=')';
    s.push('(');
    int i =0 ,j =0;
    char ch ;
    for(i =0 , j= 0;i<=size;i++)
    {
        switch (prec(infix[i])) {
            case 1:
                s.push(infix[i]);break;
            case 2:
                s.pop(ch);
                while(ch !='(')
                {
                    postfix+=ch;
                    s.pop(ch);
                }
                break;
            case 3:
                s.pop(ch);
                while(prec(ch)>=3)
                {
                    postfix+=ch;
                    s.pop(ch);
                }
                s.push(ch);
                s.push(infix[i]);
                break;
            case 4 :
                s.pop(ch);
                while(prec(ch)>=4)
                {
                    postfix+=ch;
                    s.pop(ch);
                }
                s.push(ch);
                s.push(infix[i]);
                break;
            case 5:
                s.pop(ch);
                while(prec(ch)==5)
                {
                    postfix+=ch;
                    s.pop(ch);
                }
                s.push(ch);
                s.push(infix[i]);
                break;
            default :
                postfix+=infix[i];break;
        }

    }

}*/
int main()
{


}