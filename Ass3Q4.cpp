#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

int get_precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

std::string infix_to_postfix(const std::string& infix) {
    std::stack<char> op_stack;
    std::string postfix = "";
    
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            op_stack.push(ch);
        } else if (ch == ')') {
            while (!op_stack.empty() && op_stack.top() != '(') {
                postfix += op_stack.top();
                op_stack.pop();
            }
            if (!op_stack.empty() && op_stack.top() == '(') {
                op_stack.pop();
            }
        } else { // Operator
            while (!op_stack.empty() && get_precedence(op_stack.top()) >= get_precedence(ch)) {
                postfix += op_stack.top();
                op_stack.pop();
            }
            op_stack.push(ch);
        }
    }

    while (!op_stack.empty()) {
        postfix += op_stack.top();
        op_stack.pop();
    }
    return postfix;
}

int main() {
    std::string infix_expr = "a+b*(c^d-e)^(f+g*h)-i";
    std::string postfix_expr = infix_to_postfix(infix_expr);
    std::cout << "Infix expression: " << infix_expr << std::endl;
    std::cout << "Postfix expression: " << postfix_expr << std::endl;
    return 0;
}