#include <iostream>
#include <string>

#include "../../../Data Structure Codes/Lists/StackLLBased/StackLLBAsed.h"
#include "../../../Data Structure Codes/Lists/StackLLBased/StackLLBAsed.cpp"

template<typename T>
int Stack<T>::precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/' || c== '^') {
        return 2;
    }
    return 0;
}

template<typename T>
bool Stack<T>::isOperator(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return true;
    }
    return false;
}

template<typename T>
string Stack<T>::infixToPostfix(string infix) {
    Stack<char> s;
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix += c;
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
    }

    while (!s.isEmpty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}


int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    Stack<char> s;
    string postfix = s.infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
}
