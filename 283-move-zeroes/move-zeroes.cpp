class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        for(int j=0;j<n;j++){
        for(int i =0;i<n-1;i++){
            if(nums[i]==0) swap(nums[i],nums[i+1]);
        }
        }
    }
};