#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

void initNode(Node *tmpHead,int n){
    tmpHead->data=n;
    tmpHead->next=tmpHead;

}//end method initNode

void addNode(Node *tmpHead, int n){
    Node *cur=tmpHead; //make cur point to what tmpHead pointing to
    Node *newNode=new Node;
    newNode->data=n;
    newNode->next=tmpHead;

    while(cur->next!= tmpHead){
        cur= cur->next;
    }
    cur->next= newNode;
}//end method addNode

void displayNode(Node *cur){
    Node *tmpHead= cur;

    do{
        cout << cur->data << " ";
        cur= cur->next;
    } while(cur!= tmpHead);// why not cur->next?

    cout << endl;
}//end method displayNode

void addFront(Node **tmpHead, int n){
    Node *cur= (*tmpHead);
    Node *newNode= new Node;
    newNode->data= n;
    newNode->next= (*tmpHead);

    while(cur->next != *tmpHead){
        cur= cur->next;
    }
    cur->next= newNode;
    *tmpHead= newNode;
    
}//end method addFront 

int main(){
    Node *head= new Node;
    initNode(head,22);
    addNode(head,33);
    addNode(head,44);
    displayNode(head); //22 33 44
    addFront(&head,11);
    displayNode(head); //11 22 33 44

    return 0;
    
}//end main
