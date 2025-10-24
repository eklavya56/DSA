class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int curr_sum=0; int maxsum=INT_MIN;
       int n =nums.size();
       for(int i =0;i<n;i++){
        curr_sum+=nums[i];
        maxsum=max(curr_sum,maxsum);
        if (curr_sum<=0)
        curr_sum=0;
       } 
       return maxsum;
    }
};