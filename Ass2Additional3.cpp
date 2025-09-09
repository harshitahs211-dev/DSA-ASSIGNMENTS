#include <iostream>
#include <string>
#include <vector>

bool areAnagrams(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    std::vector<int> char_counts(256, 0); 
    for (char ch : str1) {
        char_counts[ch]++;
    }

    for (char ch : str2) {
        char_counts[ch]--;
    }

    for (int count : char_counts) {
        if (count != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string s1 = "listen";
    std::string s2 = "silent";
    std::cout << "Strings: '" << s1 << "' and '" << s2 << "'" << std::endl;
    std::cout << "Are they anagrams? " << (areAnagrams(s1, s2) ? "Yes" : "No") << std::endl;

    std::string s3 = "hello";
    std::string s4 = "world";
    std::cout << "Strings: '" << s3 << "' and '" << s4 << "'" << std::endl;
    std::cout << "Are they anagrams? " << (areAnagrams(s3, s4) ? "Yes" : "No") << std::endl;
    return 0;
}