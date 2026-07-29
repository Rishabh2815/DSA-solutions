#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Define a structure to group job attributes cleanly
    struct Job {
        int startTime;
        int endTime;
        int profit;
    };

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);
        
        // 1. Combine inputs into an array of Job structures
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        // 2. Sort jobs based on their end times in ascending order
        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.endTime < b.endTime;
        });
        
        // 3. DP array where dp[i] stores the max profit using a subset of the first i jobs
        // dp is 1-indexed to cleanly handle the base case (dp[0] = 0 means no jobs)
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            // Choice A: Exclude the current job
            int excludeProfit = dp[i - 1];
            
            // Choice B: Include the current job
            int includeProfit = jobs[i - 1].profit;
            
            // Use binary search to find the latest non-overlapping job
            int latestNonOverlappingIdx = findLatestNonOverlapping(jobs, i - 1);
            
            if (latestNonOverlappingIdx != -1) {
                includeProfit += dp[latestNonOverlappingIdx + 1]; // Convert 0-indexed result to 1-indexed DP
            }
            
            // State transition: take the maximum of both choices
            dp[i] = max(excludeProfit, includeProfit);
        }
        
        return dp[n];
    }

private:
    // Binary search helper to find the last job that ends before or at the current job's start time
    int findLatestNonOverlapping(const vector<Job>& jobs, int currentIdx) {
        int low = 0;
        int high = currentIdx - 1;
        int result = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (jobs[mid].endTime <= jobs[currentIdx].startTime) {
                result = mid;     // This job is compatible, check if a later one fits too
                low = mid + 1;
            } else {
                high = mid - 1;   // Overlaps, look earlier
            }
        }
        return result;
    }
};
