#include <iostream>
#include <stack>
#include <limits>

class MinStack {
private:
    std::stack<int> main_stack;
    std::stack<int> min_stack;

public:
    void push(int val) {
        main_stack.push(val);
        if (min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        }
    }

    void pop() {
        if (!main_stack.empty()) {
            if (main_stack.top() == min_stack.top()) {
                min_stack.pop();
            }
            main_stack.pop();
        }
    }

    int peek() {
        if (!main_stack.empty()) {
            return main_stack.top();
        }
        throw std::runtime_error("Stack is empty");
    }

    int getMin() {
        if (!min_stack.empty()) {
            return min_stack.top();
        }
        throw std::runtime_error("Stack is empty");
    }
};

int main() {
    MinStack stack;
    std::cout << "Operations: push(2), push(3), push(2), pop(), getMin()" << std::endl;
    stack.push(2);
    stack.push(3);
    stack.push(2);
    stack.pop();
    try {
        std::cout << "Current minimum element: " << stack.getMin() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}