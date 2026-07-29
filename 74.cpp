#include <vector>
#include <unordered_map>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    // Step 1: Count occurrences of each number
    std::unordered_map<int, int> counts;
    for (int num : nums) {
        counts[num]++;
    }
    
    // Step 2: Group numbers by their frequency
    // Max possible frequency is nums.size(), so we need size + 1 buckets
    std::vector<std::vector<int>> buckets(nums.size() + 1);
    for (const auto& [num , freq] : counts) {
        buckets[freq].push_back(num);
    }
    
    // Step 3: Gather the top k elements from highest to lowest frequency
    std::vector<int> result;
    for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
        for (int num : buckets[i]) {
            result.push_back(num);
            if (result.size() == k) {
                break;
            }
        }
    }
    
    return result;
}
