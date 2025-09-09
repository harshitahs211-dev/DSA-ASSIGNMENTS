#include <iostream>
#include <vector>

void duplicateZeros(std::vector<int>& arr) {
    int n = arr.size();
    int zeros_to_duplicate = 0;
    int i;
    for (i = 0; i < n; ++i) {
        if (i + zeros_to_duplicate >= n) {
            break;
        }
        if (arr[i] == 0) {
            zeros_to_duplicate++;
        }
    }
    
    int original_index = i - 1;
    int new_index = original_index + zeros_to_duplicate;
    
    if (new_index >= n && arr[original_index] == 0) {
        arr[n - 1] = 0;
        original_index--;
        new_index -= 2;
    }
    
    for (; original_index >= 0; --original_index) {
        if (arr[original_index] == 0) {
            if (new_index < n) {
                arr[new_index] = 0;
            }
            new_index--;
            if (new_index < n) {
                arr[new_index] = 0;
            }
        } else {
            if (new_index < n) {
                arr[new_index] = arr[original_index];
            }
        }
        new_index--;
    }
}

int main() {
    std::vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    duplicateZeros(arr);
    std::cout << "Modified array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}