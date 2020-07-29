#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void initNode(Node *tmpHead, int n){
    tmpHead->data=n;
    tmpHead->next=NULL;
    tmpHead->prev=NULL;

}//end method initNode

void addNode(Node *cur, int n){
    Node *newNode= new Node;
    newNode->data= n;
    newNode->next= NULL;

    while(cur->next != NULL){
        cur=cur->next;
    }
    cur->next= newNode;
    newNode->prev= cur;

}//end method addNode

void displayList(Node *cur){               
    while(cur!=NULL){                      
        cout << cur->data << " ";          
        cur=cur->next;
    }

    cout << endl;

}//end method displayList

void displayReverse(Node *cur){
    while(cur->next!= NULL){
        cur=cur->next;
    }

    while(cur!= NULL){
        cout << cur->data << " ";
        cur= cur->prev;
    }
    cout << endl;

}//end method displayReverse

void addFront(Node **tmpHead, int n){
    Node *newNode= new Node;
    newNode->data= n;
    newNode->prev= NULL;
    (*tmpHead)->prev= newNode;
    newNode-> next= *tmpHead;
    *tmpHead= newNode;

}//end method addFront

void removeFront(Node **tmpHead){
    if((*tmpHead)->next== NULL)
        cout << "Single Node! removeFront aborted!\n";

    else{
    *tmpHead= (*tmpHead)->next;
    delete (*tmpHead)->prev;
    (*tmpHead)->prev= NULL;
    }
    
}//end method removeFront

int main(){
    Node *head= new Node;
    initNode(head,22);
    addNode(head,33);
    addNode(head,44);
    displayList(head);    //22 33 44
    displayReverse(head); //44 33 22
    addFront(&head,11);
    displayList(head);    //11 22 33 44
    displayReverse(head); //44 33 22 11
    removeFront(&head);
    displayList(head);    //22 33 44
    displayReverse(head); //44 33 22

    return 0;

}//end main
