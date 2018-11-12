#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* front = NULL;
Node* rear = NULL;

void enQueue(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(front == NULL){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void deQueue(){
    if(front == NULL){
        return;
    }else if(front == rear){
        front = rear = NULL;
        return;
    }
    Node* temp = front;
    front = front->next;
    free(temp);
}

void print(){
    Node* temp = front;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void peek(){
    if(front == NULL){
        return;
    }
    cout << front->data << endl;
}

int main(){
    enQueue(1);print();
    enQueue(2);print();
    enQueue(3);print();
    enQueue(4);print();
    peek();
    return 0;
}







