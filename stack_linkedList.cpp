#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* top = NULL;

void push(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop(){
    if(top == NULL){
        cout << "Error: stack is empty!";
        return;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
}

void print(){
    cout << "stack: ";
    Node* p = top;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    push(1);print();
    push(2);print();
    push(3);print();
    pop();print();
    pop();print();
    pop();print();
    pop();
}








