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

int findMin_iterate(BstNode* root){//迭代寻找最小值
    if(root == NULL){
        cout << "Error: The tree is empty!" << endl;
        return -1;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int findMax_iterate(BstNode* root){//迭代寻找最大值
    if(root == NULL){
        cout << "Error: The tree is empty!" << endl;
        return -1;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

int findMin_recursive(BstNode* root){//递归寻找最小值
    if(root == NULL){
        cout << "Error: The tree is empty!" << endl;
        return -1;
    }else if(root->left == NULL){
        return root->data;
    }
    return findMin_recursive(root->left);
}

int findMax_recursive(BstNode* root){//递归寻找最大值
    if(root == NULL){
        cout << "Error: The tree is empty!" << endl;
        return -1;
    }else if(root->right == NULL){
        return root->data;
    }
    return findMax_recursive(root->right);
}

int main(){
    BstNode* root = NULL;
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 5);
    cout << findMin_recursive(root) << endl;
    cout << findMax_recursive(root) << endl;
    return 0;
}







