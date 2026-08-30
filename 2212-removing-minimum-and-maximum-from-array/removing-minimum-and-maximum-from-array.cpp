class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx=0;
        int mn=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[mx])
            mx=i;
            if(nums[i]<nums[mn])
            mn=i;

        }
        int front=max(mx,mn)+1;
        int back=n-min(mx,mn);
        int both = min(mn, mx) + 1 + n - max(mn, mx);
        return min({front,back,both});
    }
};