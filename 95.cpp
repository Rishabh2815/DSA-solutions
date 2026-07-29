#include <iostream>
#include <string>
#include <climits> // Required for INT_MAX and INT_MIN

int myAtoi(std::string s) {
    int i = 0;
    int n = s.length();
    int sign = 1;
    int result = 0;

    // 1. Discard leading whitespaces
    while (i < n && s[i] == ' ') {
        i++;
    }

    // 2. Check for optional sign
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // 3. Process digits and handle overflow/underflow
    while (i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        // Check overflow/underflow conditions before modifying result
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}

int main() {
    // Test cases
    std::cout << myAtoi("   -42") << std::endl;       // Output: -42
    std::cout << myAtoi("4193 with words") << std::endl; // Output: 4193
    std::cout << myAtoi("words and 987") << std::endl;   // Output: 0
    std::cout << myAtoi("-91283472332") << std::endl;    // Output: -2147483648 (INT_MIN)
    return 0;
}
