#include <iostream>
#include <string>

bool is_substring(const std::string& sub, const std::string& main) {
    return main.find(sub) != std::string::npos;
}

bool solveStringSplit(const std::string& s) {
    int n = s.length();
    if (n < 3) return false;

    for (int i = 1; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::string s1 = s.substr(0, i);
            std::string s2 = s.substr(i, j - i);
            std::string s3 = s.substr(j);

            if (is_substring(s1, s2 + s3) || is_substring(s2, s1 + s3) || is_substring(s3, s1 + s2)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::string s1 = "abacaba";
    std::cout << "String: " << s1 << std::endl;
    std::cout << "Can be split? " << (solveStringSplit(s1) ? "Yes" : "No") << std::endl;
    
    std::string s2 = "abcde";
    std::cout << "String: " << s2 << std::endl;
    std::cout << "Can be split? " << (solveStringSplit(s2) ? "Yes" : "No") << std::endl;
    return 0;
}