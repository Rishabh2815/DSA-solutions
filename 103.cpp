#include <string>
#include <sstream>

class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        std::stringstream ss1(version1);
        std::stringstream ss2(version2);
        
        int num1 = 0, num2 = 0;
        char dot;
        
        // Read integers from streams; stream extraction automatically handles leading zeros
        while (ss1 >> num1 && ss2 >> num2) {
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            
            // Consume the dot separator if present
            if (ss1.peek() == '.') ss1 >> dot;
            if (ss2.peek() == '.') ss2 >> dot;
            
            // Reset values to 0 for missing trailing revisions
            num1 = 0;
            num2 = 0;
        }
        
        return 0;
    }
};
