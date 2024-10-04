#pragma Once

#include <iostream>
#include <string>

using namespace std;


class Stack{

private:

int top;
int *stack;
int max;
int min;

public:

Stack(int max);
~Stack();
bool isEmpty();
bool isFull();
void Push(int item);
void Pop(int &item);
int getMin();
int Size();
int getMaxSize();

};