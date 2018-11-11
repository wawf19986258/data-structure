#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool isOperand(char c)//仅限于字母
{
    if('a' <= c && c <= 'z') return true;
    if('A' <= c && c <= 'Z') return true;
    return false;
}

bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int getOperatorWeight(char op)
{
    int weight = 0;
    switch(op)
    {
        case '+':
        case '-':
            weight = 1;
        case '*':
        case '/':
            weight = 2;
    }
    return weight;
}

int hasHigherPrecedence(char top, char exp)//如果weight相同，则按照
//从左到右的优先级，即先进栈的优先级高
{
    int topWeight = getOperatorWeight(top);
    int expWeight = getOperatorWeight(exp);
    return topWeight >= expWeight ?  1 : 0;
}


string infixToPostfix(string exp)
{
    stack<char> s;
    string postfix = "";
    
    for(int i = 0; i< exp.length(); i++) {
        if(exp[i] == ' ' || exp[i] == ',') continue;
        else if(isOperator(exp[i]))
        {
            while(!s.empty() && s.top() != '(' && hasHigherPrecedence(s.top(),exp[i])){
                postfix += s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
        else if(isOperand(exp[i]))
        {
            postfix += exp[i];
        }
        
        else if(exp[i] == '(')
        {
            s.push(exp[i]);
        }
        
        else if(exp[i] == ')')
        {
            while(!s.empty() && s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main()
{
    string expression;
    cout<<"Enter Infix Expression \n";
    getline(cin,expression);
    string postfix = infixToPostfix(expression);
    cout<<"Output = "<<postfix<<"\n";
}
