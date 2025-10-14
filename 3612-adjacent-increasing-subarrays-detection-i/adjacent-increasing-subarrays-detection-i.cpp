class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int pre = 0, cur = 0, mx = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur++;
            if (i == nums.size() - 1 || nums[i] >= nums[i + 1]) {
                mx = max({mx, cur / 2, min(pre, cur)});
                pre = cur;
                cur = 0;
            }
        }
        return mx >= k;
    }
};
