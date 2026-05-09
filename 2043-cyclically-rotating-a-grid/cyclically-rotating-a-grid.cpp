class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers=min(m,n)/2;//each layer require two rows and two columns
        for(int layer=0;layer<layers;layer++){
            vector<int>nums;
            int top=layer; 
            int bottom=m-layer-1;
            int right=n-layer-1;
            int left=layer;
             // Top row (left -> right)
            for(int i=left;i<=right;i++){
                nums.push_back(grid[top][i]);
            }
            // Right column (top -> bottom)
            // Skip corners because they are already included in top/bottom rows
            for(int j=top+1;j<=bottom-1;j++){
                nums.push_back(grid[j][right]);
            }
             // Bottom row (right -> left)
            for(int i=right;i>=left;i--){
                nums.push_back(grid[bottom][i]);
            }
             // Left column (bottom -> top)
            // Skip corners because they are already included in top/bottom rows
            for(int j=bottom-1;j>=top+1;j--){
                nums.push_back(grid[j][left]);
            }
             int len = nums.size();
            int nomralized_k = k % len;
            rotate(begin(nums), begin(nums) + nomralized_k, end(nums));

            int idx = 0;
            for(int i=left;i<=right;i++){
                grid[top][i]=nums[idx++];
            }
            for(int j=top+1;j<=bottom-1;j++){
                grid[j][right]=nums[idx++];
            }
            for(int i=right;i>=left;i--){
                grid[bottom][i]=nums[idx++];
            }
            for(int j=bottom-1;j>=top+1;j--){
                grid[j][left]=nums[idx++];
            }
        }
        return grid;

    }
};