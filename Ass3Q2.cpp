#include <iostream>
#include <stack>
#include <string>

std::string reverse_string(const std::string& s) {
    std::stack<char> charStack;
    std::string reversed_str = "";

  
    for (char ch : s) {
        charStack.push(ch);
    }

  
    while (!charStack.empty()) {
        reversed_str += charStack.top();
        charStack.pop();
    }

    return reversed_str;
}

int main() {
    std::string input_string = "DataStructure";
    std::string reversed_string = reverse_string(input_string);
    std::cout << "Original string: " << input_string << std::endl;
    std::cout << "Reversed string: " << reversed_string << std::endl;
    return 0;
}