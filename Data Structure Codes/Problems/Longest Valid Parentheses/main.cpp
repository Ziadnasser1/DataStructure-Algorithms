#include <iostream>
#include "../../../Data Structure Codes/Lists/StackLLBased/StackLLBAsed.h"
#include "../../../Data Structure Codes/Lists/StackLLBased/StackLLBAsed.cpp"


int longestValidParentheses(string s) {
    Stack<char> st;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (st.isEmpty()) {
                continue;
            } else {
                st.pop();
                count += 2;
            }
        }
    }
    return count;
}

int main() {
    string s = ")()())";
    int len = longestValidParentheses(s);
    cout << "Length of the longest valid parentheses substring: " << len << endl;
}
