class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;

        int mx = nums[0];
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            arr.push_back(gcd(nums[i], mx));
        }
        sort(arr.begin(), arr.end());

        long long sum = 0;
        for (int i = 0; i < n / 2; i++) {
            sum += gcd(arr[i], arr[n - 1 - i]);
        }

        return sum;
    }
};