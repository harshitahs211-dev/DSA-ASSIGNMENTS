
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

int countPairsWithDiffK(const std::vector<int>& arr, int k) {
    std::unordered_set<int> seen_numbers;
    int count = 0;

    for (int num : arr) {
        if (seen_numbers.count(num - k)) {
            count++;
        }
        if (seen_numbers.count(num + k)) {
            count++;
        }
        seen_numbers.insert(num);
    }
    return count;
}

int main() {
    std::vector<int> arr = {1, 5, 3, 4, 2};
    int k = 2;
    std::cout << "Input array: {1, 5, 3, 4, 2}" << std::endl;
    std::cout << "Difference k: " << k << std::endl;
    std::cout << "Number of pairs with difference " << k << " is: " << countPairsWithDiffK(arr, k) << std::endl;
    return 0;
}
