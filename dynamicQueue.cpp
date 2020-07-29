#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

bool isEmpty(Node *tmpFront){
    return (tmpFront== NULL);
}

void enQueue(Node **tmpFront, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

    if(isEmpty(*tmpFront)){  //check if it is empty node or single node
        *tmpFront=newNode;
    }
    else{
        Node *cur= *tmpFront;  //if it's single node then come to this part
	    while (cur->next) {
		    cur = cur->next;
	}
	cur->next = newNode;
    }
}

void displayQueue(Node *cur) {
    if (isEmpty(cur)){
        cout << "Queue is empty! Nothing to display.\n";
    }
    else{
        cout << "FRONT ";  //first one on top, last one meaning at the last
	    while (cur) {
		    cout << cur->data << " ";
		    cur = cur->next;
	    }
    }
	cout << endl;
}

int deQueue(Node **tmpFront) {
    int data= -1;
    if (isEmpty(*tmpFront)){
        cout << "Queue is empty! deQueue aborted!\n";
    }
	else{
        Node *oldNode= *tmpFront;
		*tmpFront = oldNode->next;
        data= oldNode->data;
		delete(oldNode);
	    }
    return data;    
}


int getQueueSize(Node *cur) {
	int count = 0;
	while (cur) {
		count++;
		cur = cur->next;
	}
	return count;
}

int main() {
	Node *front = NULL;
    enQueue(&front, 22);
	enQueue(&front, 33);
	enQueue(&front, 44);
	displayQueue(front);  //FRONT: 22 33 44 
	cout << "DEQUEUE " << deQueue(&front) << endl;
	displayQueue(front);  // FRONT: 33 44
	cout << "Queue Size: " << getQueueSize(front) << endl;
	return 0;
}
