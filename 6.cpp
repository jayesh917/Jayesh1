#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

bool isRightAssociative(char op) {
    return (op == '^');
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } 
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(c)) {
            while (!st.empty() && isOperator(st.top())) {
                if ((isRightAssociative(c) && precedence(c) < precedence(st.top())) ||
                    (!isRightAssociative(c) && precedence(c) <= precedence(st.top()))) {
                    postfix += st.top();
                    st.pop();
                } 
                else break;
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char c : postfix) {
        if (isdigit(c)) {
            st.push(c - '0');
        }
        else if (isOperator(c)) {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int result = 0;

            if (c == '+') result = val1 + val2;
            else if (c == '-') result = val1 - val2;
            else if (c == '*') result = val1 * val2;
            else if (c == '/') result = val1 / val2;
            else if (c == '^') result = pow(val1, val2);

            st.push(result);
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    bool hasDigits = false;
    for (char c : postfix) {
        if (isdigit(c)) hasDigits = true;
    }

    if (hasDigits)
        cout << "Result: " << evaluatePostfix(postfix);
    else
        cout << "Non-numeric expression.";

    return 0;
}
