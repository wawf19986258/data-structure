#include<iostream>
#include<queue>
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

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int findHeight(BstNode* root){
    if(root == NULL) return -1;
    return max(findHeight(root->left), findHeight(root->right))+1;
}

void levelOrder(BstNode* root){
    queue<BstNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        BstNode* current = Q.front();
        cout << current->data << " ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();
    }
}

void preOrder(BstNode* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BstNode* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(BstNode* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    BstNode* root = NULL;
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    levelOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    return 0;
}







