#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // for isdigit and isalpha

using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // For non-operators
}

// Function to check if the character is an operand
bool isOperand(char c) {
    return isalpha(c) || isdigit(c); // You can modify this for other types of operands
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> opStack;   // Stack to hold operators
    string postfix;         // Resultant postfix expression

    for (char c : infix) {
        // If the character is an operand, add it to the output
        if (isOperand(c)) {
            postfix += c; // Append operand to postfix
        } 
        // If the character is '(', push it to the stack
        else if (c == '(') {
            opStack.push(c);
        } 
        // If the character is ')', pop from the stack to output until '(' is encountered
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Remove '(' from the stack
        } 
        // If the character is an operator
        else {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfix += opStack.top(); // Pop operators from the stack to output
                opStack.pop();
            }
            opStack.push(c); // Push the current operator onto the stack
        }
    }

    // Pop all the remaining operators from the stack
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix; // Return the final postfix expression
}

int main() {
    string infixExpression;

    cout << "Enter an infix expression: ";
    getline(cin, infixExpression); // Read the infix expression

    string postfixExpression = infixToPostfix(infixExpression);

    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
