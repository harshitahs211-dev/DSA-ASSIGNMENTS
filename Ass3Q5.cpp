#include <iostream>
#include <string>
#include <stack>
#include <sstream>

double apply_operator(char op, double b, double a) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }
    if (op == '^') return pow(a, b);
    return 0;
}

double evaluate_postfix(const std::string& expression) {
    std::stack<double> val_stack;
    std::stringstream ss(expression);
    std::string token;
    
    while (ss >> token) {
        if (isdigit(token[0])) {
            val_stack.push(stod(token));
        } else { // Operator
            if (val_stack.size() < 2) {
                throw std::runtime_error("Invalid postfix expression");
            }
            double operand2 = val_stack.top();
            val_stack.pop();
            double operand1 = val_stack.top();
            val_stack.pop();
            double result = apply_operator(token[0], operand2, operand1);
            val_stack.push(result);
        }
    }
    
    if (val_stack.size() == 1) {
        return val_stack.top();
    } else {
        throw std::runtime_error("Invalid postfix expression");
    }
}

int main() {
    std::string postfix_expr = "5 2 + 3 * 4 /";
    try {
        double result = evaluate_postfix(postfix_expr);
        std::cout << "Postfix expression: " << postfix_expr << std::endl;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}