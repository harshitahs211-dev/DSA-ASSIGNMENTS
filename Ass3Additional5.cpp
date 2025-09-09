#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

void sort_stack(std::stack<int>& s) {
    std::stack<int> temp_stack;

    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        while (!temp_stack.empty() && temp_stack.top() > temp) {
            s.push(temp_stack.top());
            temp_stack.pop();
        }
        temp_stack.push(temp);
    }

    while (!temp_stack.empty()) {
        s.push(temp_stack.top());
        temp_stack.pop();
    }
}

int main() {
    std::stack<int> my_stack;
    my_stack.push(2);
    my_stack.push(4);
    my_stack.push(1);
    my_stack.push(3);

    std::cout << "Original stack (top to bottom):" << std::endl;
    std::stack<int> temp_display = my_stack;
    while (!temp_display.empty()) {
        std::cout << temp_display.top() << " ";
        temp_display.pop();
    }
    std::cout << std::endl;

    sort_stack(my_stack);

    std::cout << "Sorted stack (top to bottom):" << std::endl;
    while (!my_stack.empty()) {
        std::cout << my_stack.top() << " ";
        my_stack.pop();
    }
    std::cout << std::endl;
    
    return 0;
}