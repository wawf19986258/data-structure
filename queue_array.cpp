#include<iostream>

#include<string>
#define Max_Size 101
using namespace std;
class Queue{
private:
    int A[Max_Size];
    int front, rear;
public:
    void enQueue(int x);
    void deQueue();
    bool isEmpty();
    bool isFool();
    int peek();
    void print();
    Queue(){
        front = rear = -1;
    }
};
bool Queue::isEmpty(){
    return (front == -1 && rear == -1);
}

bool Queue::isFool(){
    return ((rear+1)%Max_Size == front) ? true:false;
}

void Queue::enQueue(int x){
    if(isFool()){
        cout << "Error: The queue is fool!" << endl;
        return;
    }else if(isEmpty()){
        front = rear = 0;
        A[rear] = x;
        return;
    }
    rear = (rear+1)%Max_Size;
    A[rear] = x;
}

void Queue::deQueue(){
    if(isEmpty()){
        cout << "Error: The queue is empty!" << endl;
        return;
    }else if(front == rear){
        front = rear = -1;
        return;
    }else{
        front = (front + 1)%Max_Size;
    }
}

int Queue::peek(){
    if(isEmpty()){
        cout << "Error: The queue is empty! ";
        return -1;
    }
    return A[front];
}

void Queue::print(){
    if(isEmpty()){
        cout << "Error: The queue is empty!" << endl;
        return;
    }
    int count = (rear+Max_Size-front)%Max_Size + 1;
    for(int i = 0; i < count; i++){
        cout << A[(front+i)%Max_Size] << " ";
    }
    cout << endl;
}


int main(){
    Queue q;
    q.enQueue(1);q.print();
    q.enQueue(2);q.print();
    q.enQueue(3);q.print();
    return 0;
}


