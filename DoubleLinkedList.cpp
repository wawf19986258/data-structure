#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* head = NULL;
Node* getNewNode(int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(int x){
    Node* newNode = getNewNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void print(){
    Node* p = head;
    if(head == NULL){
        return;
    }
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}

void print_reverse(){
    Node* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    while(p != NULL){
        cout << p->data << " ";
        p = p->prev;
    }
}

int main(){
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    print_reverse();
    cout << endl;
    print();
    cout << endl;
}








