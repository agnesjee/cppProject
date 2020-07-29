#include <iostream>
using namespace std;

int main(){

    struct Node{
        int data;
        Node *next;
    };

    Node *head = new Node;
    head -> data = 10;
    head -> next = NULL;
    Node *newNode = new Node;
    newNode -> data = 20;
    newNode -> next = NULL;
    Node *cur = head;

    while(cur){
        if(cur -> next == NULL){
            cur -> next = newNode;
            break;
        }
        cur = cur -> next;
    }

    cur = head;

    while(cur){
        cout << cur->data << "\n";
        cur = cur->next;
    }

return 0;
}//end main
