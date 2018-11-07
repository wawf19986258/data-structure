#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

void insert_head(Node*& head, int x){//头插法
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insert_tail(Node*& head, int x){//尾插法
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    Node* p = head;
    while(p->next != NULL)
        p = p->next;
    p->next = temp;
}

void insert(Node*& head, int po, int x){//从任意位置插入
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(po == 1){
        temp->next = head;
        head = temp;
        return;
    }
    Node* p = head;
    for(int n = 1; n < po-1; n++){
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

void delete_po(Node*& head, int po){//根据下标索引删除链表中的元素
    Node* temp = head;
    if(po == 1){
        head = temp->next;
        delete temp;
        return;
    }
    Node* p = head;
    for(int i = 1; i < po-1; i++){
        p = p->next;
    }
    temp = p->next;
    p->next = temp->next;
    delete temp;
}

void reverse_iterative(Node*& head){//逆序链表(通过迭代)
    Node* prev = NULL;
    Node* curr = head;
    Node* next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void reverse_recursion(Node*& head, Node* p){//逆序链表(通过递归)
    if(p->next == NULL){
        head = p;
        return;
    }
    reverse_recursion(head, p->next);
    p->next->next = p;
    p->next = NULL;
}

void print_iterative(Node*& head){//顺序输出链表（通过迭代）
    Node* p = head;
    while(p != NULL){
        cout << p->data<< " ";
        p = p->next;
    }
}

void print_order(Node*& head){//顺序输出列表（通过递归）
    if(head == NULL) return;
    cout << head->data << " ";
    print_order(head->next);
}

void print_reverse(Node*& head){//逆序输出列表（通过递归)
    if(head == NULL) return;
    print_reverse(head->next);
    cout << head->data << " ";
}

int main(){
    Node* head = NULL;
    insert(head,1,5);
    insert(head,2,6);
    insert(head,3,7);
    insert(head,4,8);
    print_order(head);
    cout << endl;
    reverse_recursion(head, head);
    print_order(head);
    cout << endl;
    cout << endl;
}









