class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, long long> rightFreq, leftFreq;
        for (int x : nums) rightFreq[x]++;
        long long ans = 0;
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            int val = nums[j];
            rightFreq[val]--;
            long long target = 2LL * val;
            if (leftFreq.count(target) && rightFreq.count(target)) {
                ans = (ans + leftFreq[target] * rightFreq[target]) % MOD;
            }
            leftFreq[val]++;
        }
        return ans;
    }
    int specialTriplets(vector<int>& nums) {
        return countTriplets(nums);
    }
};
