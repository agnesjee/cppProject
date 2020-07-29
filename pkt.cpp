#include <iostream>
using namespace std;

struct Node {
    int id;
    Node *left;
    Node *up;
    Node *right;
};

int main() {
    Node *root = new Node;
    root->id = -1;
    Node *branch[10];

    for (int k=0; k<7; k++) {
    branch[k] = new Node;
    branch[k]->id = k;
    }

    root->left = branch[0];
    root->up = branch[1];
    root->right = branch[2];
    branch[0]->left = branch[3];
    branch[0]->up = branch[4];
    branch[2]->up = branch[5];
    branch[2]->right = branch[6];
    cout << root->left->up->id << endl;
    cout << root->right->right->id << endl;
    branch[6]->up = branch[5];
    branch[5]->left = branch[0];
    cout << root->right->right->up->left->up->id<<endl;

    return 0;
}
