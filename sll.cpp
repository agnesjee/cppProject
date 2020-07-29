#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void initNode(Node *tmpHead, int n){
    tmpHead->data=n;
    tmpHead->next=NULL;

}//end method initNode

void addNode(Node *cur,int n){
    Node *newNode=new Node;
    newNode->data=n;
    newNode->next=NULL;

    while(cur->next != NULL){
        cur=cur->next;
    }
    cur->next=newNode;

}//end method addNode

void displayNode(Node *cur){               //1. Node *cur 2. cur=head
    while(cur!=NULL){                      //while(cur)
        cout << cur->data << " ";          //output data
        cur=cur->next;
    }

    cout << endl;

}//end method displayNode

void addFront(Node **tmpHead, int n){      //double pointer, result tmpHead pointing to head
    Node *newNode=new Node;
    newNode->data=n;
    newNode->next=*tmpHead;
    *tmpHead=newNode;

}//end method addFront

void removeFront(Node **tmpHead){
    if((*tmpHead)->next== NULL){
        cout << "Single Node! removeFront aborted.\n";
    }
    else{
    Node *oldHead= *tmpHead;
    *tmpHead= oldHead ->next;
    delete oldHead;
    }
}//end method removeFront

void removeNode(Node *cur){
    if(cur->next== NULL){
        cout << "Single Node! removeNode aborted.\n";
    }
    else{
        while(cur->next->next!=NULL){ //goes to the second last node
            cur=cur->next;
        }
        delete cur->next;
        cur->next=NULL;
    }  
}//end method removeNode

int getTotalNode(Node *cur){
    int count=0;
    while(cur!=NULL){
        count++;
        cur= cur->next;
    }

    return count;

}//end method getTotalNode

int main (){
    Node *head=new Node;
    initNode(head,22);
    addNode(head,33);
    displayNode(head); //22 33
    addFront(&head,11);
    displayNode(head);//11 22 33
    cout << "Total: " << getTotalNode(head) << endl; //Total:3
    removeFront(&head);
    displayNode(head);//22 33
    removeNode(head);
    displayNode(head);//22
    cout << "Total: " << getTotalNode(head) << endl; //Total:1

    return 0;
    
}//end main
