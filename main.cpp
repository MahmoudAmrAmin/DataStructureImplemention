#include<iostream>
#include"list.h"

using namespace std;
#define Endl endl;

int main()
{
   linked_list<int>t;
   t.push_front(5);
   t.push_back(10);
   t.insertAtPosition(2,15);
   t.print();



}