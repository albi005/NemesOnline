// 65/100
// Created using ChatGPT

#include <iostream>
#include <vector>
#include <unordered_map>

std::pair<int, int> longestIntervalWithSumK(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> presum;
    int max_len = 0, sum = 0, start = -1, end = -1;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum == k) {
            if (i + 1 > max_len) {
                max_len = i + 1;
                start = 0;
                end = i;
            }
        } else if (presum.find(sum - k) != presum.end()) {
            int len = i - presum[sum - k];
            if (len > max_len) {
                max_len = len;
                start = presum[sum - k] + 1;
                end = i;
            }
        } else {
            presum[sum] = i;
        }
    }
    return std::make_pair(start, end);
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    auto result = longestIntervalWithSumK(nums, k);
    std::cout << result.first + 1 << " " << result.second + 1 << std::endl;
    return 0;
}
