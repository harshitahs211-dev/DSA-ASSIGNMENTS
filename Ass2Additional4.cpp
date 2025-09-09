#include <iostream>
#include <vector>

void sort012(std::vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            std::swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            std::swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    std::vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0, 2};
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sort012(arr);
    std::cout << "Sorted array:   ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}