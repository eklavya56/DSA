class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // Rule 1: path must start at (0,0)
        if(grid[0][0] != 0) return false;

        int total = n * n;

        // Store positions of each value
        vector<pair<int,int>> pos(total);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                pos[grid[i][j]] = {i, j};
            }
        }

        // Validate each consecutive move
        for(int k = 0; k < total - 1; k++){
            auto [r1, c1] = pos[k];
            auto [r2, c2] = pos[k+1];

            int dr = abs(r1 - r2);
            int dc = abs(c1 - c2);

            if(!((dr == 2 && dc == 1) || (dr == 1 && dc == 2))) {
                return false;
            }
        }

        return true;
    }
};
