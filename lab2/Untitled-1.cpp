#include<iostream>
#include<stack>

using namespace std;//stacks LIFO (last in forst out)



int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; 
    return 0;
}

string topost(const string &exp) {
    stack<char> operators;
    string output;

    for (char temp : exp) {
        // If the character is an operand, add it to the output string
        if (isalnum(temp)) {
            output += temp;
        }
        // If the character is '(', push it to the stack
        else if (temp == '(') {
            operators.push(temp);
        }
        // If the character is ')', pop from stack to output until '(' is encountered
        else if (temp == ')') {
            while (!operators.empty() && operators.top() != '(') {
                output += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove '(' from stack
        }
        // If the character is an operator
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(temp)) {
                output += operators.top();
                operators.pop();
            }
            operators.push(temp);
        }
    }

    // Pop all remaining operators from the stack
    while (!operators.empty()) {
        output += operators.top();
        operators.pop();
    }

    return output;
}


int evaluatePostfix(const string& expression) {
    stack<int> stack;

    for (int i=0;i<expression.length();i++) {
        
        if (isdigit(expression[i])) {
            stack.push(expression[i] - '0'); //chk ltr but easy
        }
       
        else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            switch (expression[i]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
            }
        }
    }
    return stack.top();
}


int main(){
    string exp="23+3*2+";

    int ans=evaluatePostfix(exp);

    cout<<"ans is: "<<ans<<endl;
}