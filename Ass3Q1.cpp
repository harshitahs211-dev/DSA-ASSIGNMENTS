#include <iostream>
#include <vector>
#include <string>

template <typename T>
class Stack {
private:
    std::vector<T> elements;
    int size;

public:
    Stack(int s) : size(s) {}

    bool is_empty() {
        return elements.empty();
    }

    bool is_full() {
        return elements.size() >= size;
    }

    void push(T item) {
        if (!is_full()) {
            elements.push_back(item);
            std::cout << "Pushed " << item << " onto the stack." << std::endl;
        } else {
            std::cout << "Error: Stack is full. Cannot push." << std::endl;
        }
    }

    T pop() {
        if (!is_empty()) {
            T item = elements.back();
            elements.pop_back();
            std::cout << "Popped " << item << " from the stack." << std::endl;
            return item;
        } else {
            std::cout << "Error: Stack is empty. Cannot pop." << std::endl;
            return T(); // Returns default value
        }
    }

    T peek() {
        if (!is_empty()) {
            T item = elements.back();
            std::cout << "Top element is " << item << "." << std::endl;
            return item;
        } else {
            std::cout << "Error: Stack is empty. Cannot peek." << std::endl;
            return T();
        }
    }

    void display() {
        if (is_empty()) {
            std::cout << "Stack is empty." << std::endl;
        } else {
            std::cout << "Stack elements:" << std::endl;
            for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
                std::cout << *it << std::endl;
            }
        }
    }
};

void run_stack_program() {
    int size;
    std::cout << "Enter the size of the stack: ";
    std::cin >> size;
    Stack<int> myStack(size);
    int choice;

    while (true) {
        std::cout << "\nStack Operations Menu:" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Check if Empty" << std::endl;
        std::cout << "4. Check if Full" << std::endl;
        std::cout << "5. Peek (Top element)" << std::endl;
        std::cout << "6. Display" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int item;
            std::cout << "Enter element to push: ";
            std::cin >> item;
            myStack.push(item);
        } else if (choice == 2) {
            myStack.pop();
        } else if (choice == 3) {
            if (myStack.is_empty()) {
                std::cout << "Stack is empty." << std::endl;
            } else {
                std::cout << "Stack is not empty." << std::endl;
            }
        } else if (choice == 4) {
            if (myStack.is_full()) {
                std::cout << "Stack is full." << std::endl;
            } else {
                std::cout << "Stack is not full." << std::endl;
            }
        } else if (choice == 5) {
            myStack.peek();
        } else if (choice == 6) {
            myStack.display();
        } else if (choice == 7) {
            std::cout << "Exiting program." << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

int main() {
    run_stack_program();
    return 0;
}