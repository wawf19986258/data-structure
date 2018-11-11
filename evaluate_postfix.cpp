#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperator(char c){
    if(c == '+'  || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

bool isNumericDigit(char c){
    if(c >= '0' && c <= '9')
        return true;
    return false;
}

int performOperation(char operation, int operand1, int operand2){
    if(operation == '+') return operand1 + operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;
    else cout << "unexpected value!" << endl;
    return -1;
}

int EvaluatePostfix(string exp){
    stack<int> s;
    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == ' ' || exp[i] == ',') continue;
        else if(isOperator(exp[i])){
            int operand2 = s.top();s.pop();
            int operand1 = s.top();s.pop();
            int result = performOperation(exp[i], operand1, operand2);
            s.push(result);
        }
        else if(isNumericDigit(exp[i])){
            int operand = 0;
            while(isNumericDigit(exp[i])){
                operand = operand * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            s.push(operand);
        }
    }
    return s.top();
}

int main(){
    string exp;
    getline(cin, exp);
    cout << EvaluatePostfix(exp) << endl;
    return 0;
}










