#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool arePair(char open, char close){
    if(open == '[' && close == ']')
        return true;
    else if(open == '{' && close == '}')
        return true;
    else if(open == '(' && close == ')')
        return true;
    else
        return false;
}

bool areParenthesesBalanced(string s){
    stack<char> stack;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '[' || s[i] == '{' || s[i] == '('){
            stack.push(s[i]);
        }else{
            if(stack.empty() || !arePair(stack.top(), s[i])){
                return false;
            }
            else{
                stack.pop();
            }
        }
    }
    return stack.empty()? true:false;
}

int main(){
    if(areParenthesesBalanced("(())")){
        cout << "balanced!" << endl;
    }else{
        cout << "not balanced!" << endl;
    }
    return 0;
}









