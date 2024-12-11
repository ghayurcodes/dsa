#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> operators;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char current = infix[i];

        if (isalnum(current)) {
            postfix += current;
        } else if (current == '(') {
            operators.push(current);
        } else if (current == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else if (current == '+' || current == '-' || current == '*' || current == '/' || current == '^') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(current)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(current);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
