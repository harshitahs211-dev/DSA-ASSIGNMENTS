#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

bool is_balanced(const std::string& expression) {
    std::stack<char> charStack;
    std::unordered_map<char, char> mapping = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            charStack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (charStack.empty() || charStack.top() != mapping[ch]) {
                return false;
            }
            charStack.pop();
        }
    }

    return charStack.empty();
}

int main() {
    std::string test_cases[] = {"()", "()[]{}", "(]", "([)]", "{[()]}"};
    for (const auto& case_str : test_cases) {
        if (is_balanced(case_str)) {
            std::cout << "The expression '" << case_str << "' has balanced parentheses." << std::endl;
        } else {
            std::cout << "The expression '" << case_str << "' does not have balanced parentheses." << std::endl;
        }
    }
    return 0;
}