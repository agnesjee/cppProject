#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

bool isEmpty(Node *tmpTop){
    return (tmpTop== NULL);
}

void displayStack(Node *cur) {
	if(isEmpty(cur)){
        cout << "Stack is empty! Nothing to display.\n";
    }
    else{
        while (cur) {
		    cout << cur->data << " ";
		    cur = cur->next;
	    }
	}
	cout << endl;
}

void push(Node **tmpTop, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *tmpTop;
	*tmpTop = newNode;
}

int pop(Node **tmpTop) {
    int data= -1;

    if(isEmpty(*tmpTop)){
        cout << "Stack is empty! Nothing to pop.\n";
    }
    else{
	    Node *oldTop = *tmpTop;
		*tmpTop = oldTop->next;
        data= oldTop->data;
		delete(oldTop);
    }
    return data;
}

int getStackSize(Node *cur) {
	int count = 0;
	while (cur) {
		count++;
		cur = cur->next;
	}
	return count;
}

int main() {
	Node *top = NULL; //real structure starts with empty
	push(&top,11);
    push(&top,22);
    push(&top,33);
	displayStack(top);
	cout << "POP " << pop(&top) << endl;
	displayStack(top);
    cout << "POP " << pop(&top) << endl;
	displayStack(top);
	cout << "Stack Size : " << getStackSize(top) << endl;
	return 0;
}
