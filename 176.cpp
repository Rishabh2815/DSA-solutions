#include <bits/stdc++.h>
using namespace std;

class solution{
public:

    // Function to find the minimum sum path in grid
    int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    
        // Create 1D vector for previous row
        vector<int> prev(m, 0);
    
        // Loop through each row
        for (int i = 0; i < n; i++) {
        
            // Create temp vector for current row
            vector<int> temp(m, 0);
        
            // Loop through each column
            for (int j = 0; j < m; j++) {
            
                // If at the start cell
                if (i == 0 && j == 0)
                    temp[j] = matrix[i][j];
                else {
                    
                    // Take up direction if valid
                    int up = matrix[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;
                    
                    // Take left direction if valid
                    int left = matrix[i][j];
                    if (j > 0)
                        left += temp[j - 1];
                    else
                        left += 1e9;
                    
                    // Take minimum of both directions
                    temp[j] = min(up, left);
                }
            }
    
            // Move current row to previous
            prev = temp;
        }
    
        // Return result at destination
        return prev[m - 1];
    }
};

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();
    
    Solution obj;
    
    cout << "Minimum sum path: " << obj.minSumPath(n, m, matrix) << endl;
    return 0;
}
