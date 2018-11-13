#include<iostream>
using namespace std;

struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* getNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* insert(BstNode* root, int data){
    if(root == NULL){
        root = getNewNode(data);
    }else if(data < root->data){
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(BstNode* root, int data){
    if(root == NULL){
        return false;
    }else if(data == root->data){
        return true;
    }else if(data < root->data){
        return search(root->left, data);
    }else{
        return search(root->right, data);
    }
}

int main(){
    BstNode* root = NULL;
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 5);
    int num;
    cin >> num;
    if(search(root, num))
        cout << "Found" << endl;
    else
        cout << "notFound" << endl;
    return 0;
}







