#include <bits/stdc++.h>
using namespace std;

// Function to find minimum number of attempts 
// needed in order to find the critical floor
int eggDrop(int n, int k) {

    // create a 2D table to store the results
    vector<vector<int>> dp(k + 1, 
                vector<int>(n + 1, 0));

    // to count the number of moves
    int cnt = 0;

    // while the number of floors is less than k
    while (dp[cnt][n] < k) {
        cnt++;

        // for each egg
        for (int i = 1; i <= n; i++) {
            dp[cnt][i] = 1 + dp[cnt - 1][i - 1] + 
                        dp[cnt - 1][i];
        }
    }
    return cnt;
}

int main() {
    int n = 2, k = 10;
    cout << eggDrop(n, k);
    return 0;
}