#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for (int s = 0; s < n; s++) {
            int sum = 0;
            for (int end = s; end < n; end++) {
                sum += nums[end];
                if (sum == k) count++;
            }
        }
        return count;
    }
};
