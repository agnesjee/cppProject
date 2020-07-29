#include <iostream>
using namespace std;

#define MAX 5

struct Stack{
    int data[MAX];
    int top;
};

int getSize(int tmpTop){
    return tmpTop+1;
}//end method getSize

bool isFull(int tmpTop){
    return (tmpTop== (MAX-1));
}

void push(Stack *ptrStack, int n){
    if (isFull(ptrStack->top)){
        cout << "Stack is full! Push aborted!\n";
    }
    else{
        ptrStack->top++;
        ptrStack->data[ptrStack->top]=n;
    }
    cout << "SIZE IN: " << getSize(ptrStack->top) << endl; //1

}//end method push

bool isEmpty(int tmpTop){
    return (tmpTop== -1);
}

void displayStack(Stack tmpStack){
    if(isEmpty(tmpStack.top)){
        cout << "Stack is empty! DisplayStack aborted!\n";
    }

    for(int k=0;k<= tmpStack.top;k++){
        cout << tmpStack.data[k] << " ";
    }
    cout << "TOP\n";
}

int pop(Stack *ptrStack){
    int data= -1;

    if(isEmpty(ptrStack->top)){
        cout << "Stack is empty! DisplayStack aborted!\n";
    }
    else{
        data= ptrStack->data[ptrStack->top];
        ptrStack->top--;
    }

    return data;
}

int main(){
    Stack aStack;
    aStack.top= -1;
    cout << "SIZE BEFORE: " << getSize(aStack.top) << endl; //0
    push(&aStack,22);
    push(&aStack,33);
    push(&aStack,44);
    displayStack(aStack); //22 33 44 TOP
    cout << "SIZE AFTER: " << getSize(aStack.top) << endl; //3
    cout << "POP " << pop(&aStack) << endl;
    displayStack(aStack); //22 33 TOP

    return 0;

}//end main
