#include <iostream>
#include <vector>
#include <stack>

std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
    int n = temperatures.size();
    std::vector<int> result(n, 0);
    std::stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int prev_index = s.top();
            s.pop();
            result[prev_index] = i - prev_index;
        }
        s.push(i);
    }
    return result;
}

int main() {
    std::vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> days_to_wait = dailyTemperatures(temps);
    std::cout << "Input: [73, 74, 75, 71, 69, 72, 76, 73]" << std::endl;
    std::cout << "Output: [";
    for (size_t i = 0; i < days_to_wait.size(); ++i) {
        std::cout << days_to_wait[i] << (i == days_to_wait.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
    return 0;
}