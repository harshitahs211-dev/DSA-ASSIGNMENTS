#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nearestSmallerElement(const std::vector<int>& nums) {
    std::vector<int> result;
    std::stack<int> s;

    for (int num : nums) {
        while (!s.empty() && s.top() >= num) {
            s.pop();
        }

        if (s.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(s.top());
        }
        s.push(num);
    }
    return result;
}

int main() {
    std::vector<int> input1 = {4, 5, 2, 10, 8};
    std::vector<int> output1 = nearestSmallerElement(input1);
    std::cout << "Input: [4, 5, 2, 10, 8]" << std::endl;
    std::cout << "Output: [";
    for (size_t i = 0; i < output1.size(); ++i) {
        std::cout << output1[i] << (i == output1.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    std::vector<int> input2 = {1, 3, 2, 4};
    std::vector<int> output2 = nearestSmallerElement(input2);
    std::cout << "Input: [1, 3, 2, 4]" << std::endl;
    std::cout << "Output: [";
    for (size_t i = 0; i < output2.size(); ++i) {
        std::cout << output2[i] << (i == output2.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    return 0;
}