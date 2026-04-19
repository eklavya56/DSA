class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int low = i, high = m - 1;
            int best = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (nums2[mid] >= nums1[i]) {
                    best = mid;      // valid j found
                    low = mid + 1;  // try to go farther right
                } else {
                    high = mid - 1;
                }
            }

            if (best != -1) {
                ans = max(ans, best - i);
            }
        }

        return ans;
    }
};