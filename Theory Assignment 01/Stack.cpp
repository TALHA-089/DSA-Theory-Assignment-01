#pragma once
#include "Stack.h"


Stack::Stack(int max) {
    top = -1;
    this->max = max;
    stack = new int[max];
}

Stack::~Stack() {
    delete[] stack;
}

bool Stack::isEmpty() {
    return (top == -1);
}

bool Stack::isFull() {
    return (top == max - 1);
}

void Stack::Push(int item) {
    if (isFull()) {
        cout << "\nStack Overflow!\n";
        return;
    }
    
    if (top == -1) {
        top++;
        min = item;
        stack[top] = item;
    } else {
        top++;
        if (item < min) {
            stack[top] = 2 * item - min;
            min = item;
        } else {
            stack[top] = item;
        }
    }
}

void Stack::Pop(int &item) {
    if (isEmpty()) {
        cout << "\nStack Underflow\n";
        return;
    }

    int poppedValue = stack[top];
    top--;

    if (poppedValue < min) {
        item = min;
        min = 2 * min - poppedValue;
    } else if(top == 0) {
        item = poppedValue;
    }else{
        item = poppedValue;
    }

    if (top == -1) {
        min = 0;
    }
}

int Stack::Size() {
    return this->top + 1;
}

int Stack::getMin() {
    if (isEmpty()) {
        cout << "\nStack is Empty\n";
        return 0;
    }
    return min;
}

int Stack::getMaxSize() {
    return this->max;
}

int Stack::peek(){
    if(top != -1){
        return stack[top];
    }else{
        return -1;
    }
}
