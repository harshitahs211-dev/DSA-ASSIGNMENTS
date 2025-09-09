#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

std::vector<int> nextGreaterElement(const std::vector<int>& nums) {
    std::vector<int> result(nums.size(), -1);
    std::stack<int> s;

    for (int i = 0; i < nums.size(); ++i) {
        while (!s.empty() && nums[s.top()] < nums[i]) {
            result[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }
    return result;
}

int main() {
    std::vector<int> input1 = {4, 5, 2, 25};
    std::vector<int> output1 = nextGreaterElement(input1);
    std::cout << "Input: [4, 5, 2, 25]" << std::endl;
    std::cout << "Output: [";
    for (size_t i = 0; i < output1.size(); ++i) {
        std::cout << output1[i] << (i == output1.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    std::vector<int> input2 = {13, 7, 6, 12};
    std::vector<int> output2 = nextGreaterElement(input2);
    std::cout << "Input: [13, 7, 6, 12]" << std::endl;
    std::cout << "Output: [";
    for (size_t i = 0; i < output2.size(); ++i) {
        std::cout << output2[i] << (i == output2.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
    return 0;
}