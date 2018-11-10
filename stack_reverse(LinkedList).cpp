#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;

void Reverse(char* a, int n){
    for(int i = 0; i < n; i++){
        s.push(a[i]);
    }
    for(int i = 0; i < n; i++){
        a[i] = s.top();
        s.pop();
    }
}

void print(char* a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    cout << endl;
}

int main(){
    char a[] = "hello";
    Reverse(a, sizeof(a));
    print(a, sizeof(a));
    return 0;
}









