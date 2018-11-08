#include <iostream>
using namespace std;

#define MaxSize 101
int top = -1;
int A[MaxSize];

void push(int x){
    if(top == (MaxSize - 1)){
        cout << "Error: stack overflow!" << endl;
        return;
    }
    A[++top] = x;
}

void pop(){
    if(top == -1){
        cout << "Error: stack is no element to pop!" << endl;
    }
    top--;
}

int getTop(){
    if(top == -1){
        cout << "Error:stack is no element!" << endl;
        return 0;
    }
    return A[top];
}

void print(){
    cout << "stack:";
    for(int i = 0; i <= top; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}


int main(){
    push(1);print();
    push(2);print();
    push(3);print();
    pop();print();
    pop();
    pop();
    pop();
    

}








