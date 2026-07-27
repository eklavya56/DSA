class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            result=(nums[n-1]-1)*(nums[n-2]-1);
        }
        return result;
    }
};