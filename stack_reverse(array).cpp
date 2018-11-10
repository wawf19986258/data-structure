#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node* next;
};
stack<Node*> s;
Node* head = NULL;

void Reverse(){//逆序链表
    if(head == NULL){
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        s.push(temp);
        temp = temp->next;
    }
    head = temp = s.top();
    s.pop();
    while(!s.empty()){
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void print(){//输出打印链表
    cout << "stack: ";
    Node* p = head;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void insert(int x){//通过插入元素生成链表
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    print();
    Reverse();
    print();
}








