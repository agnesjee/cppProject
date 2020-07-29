#include <iostream>
using namespace std;

//binary search tree
struct BSTNode{
    int key;
    BSTNode *leftChild;
    BSTNode *rightChild;
};

void initBST(BSTNode *tmpNode, int key){
    tmpNode->key = key;
    tmpNode->leftChild = NULL;
    tmpNode->rightChild = NULL;
}

// inserts a new node in the BST at the correct position
void insertBST(BSTNode* node, int key) {
    if(key < node->key) {
        if(node->leftChild != NULL)
            insertBST(node->leftChild, key); //recursion
        else {
            BSTNode *newNode = new BSTNode;  //creating a new node
            newNode->key = key;
            newNode->leftChild = NULL;
            newNode->rightChild =NULL;
            node->leftChild = newNode;
        }
    }

    else if (key >= node->key) {
        if(node->rightChild != NULL)
            insertBST(node->rightChild, key);
        else {
            BSTNode *newNode = new BSTNode;
            newNode->key = key;
            newNode->leftChild = NULL;
            newNode->rightChild =NULL;
            node->rightChild = newNode;
        }
    }
}

// search and return the matching node
BSTNode *searchBST(BSTNode *tmpNode, int key){
    cout << "step\n";
    if (tmpNode != NULL) {
        if(key == tmpNode->key)
            return tmpNode;
        else {
            if (key < tmpNode->key)
                return searchBST(tmpNode->leftChild, key);
            else
                return searchBST(tmpNode->rightChild, key);
        }
    }
    else
        return NULL;
}

int main(){
    BSTNode *root = new BSTNode;
    initBST(root, 8);
    insertBST(root, 3);
    insertBST(root, 6);
    insertBST(root, 10);
    insertBST(root, 1);
    insertBST(root, 14);
    insertBST(root, 7);
    insertBST(root, 4);
    insertBST(root, 13);
    int searchedKey = 7;
    BSTNode *searchedNode;
    searchedNode = searchBST(root, searchedKey);

    if (searchedNode != NULL) {
        cout << "KEY = " << searchedNode->key << endl;

        if (searchedNode->leftChild == NULL)
            cout << "LCHILD = NULL\n";
        else
            cout << "LCHILD = " << searchedNode->leftChild->key << endl;

        if (searchedNode->rightChild == NULL)
            cout << "RCHILD = NULL\n";
        else
            cout << "RCHILD = " << searchedNode->rightChild->key << endl;
    }

    else
        cout << searchedKey << " Not Found!";


    return 0;
}
