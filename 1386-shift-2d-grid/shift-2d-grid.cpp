class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        while (k--) {
            vector<vector<int>> temp = grid;

            // Move every element one step to the right
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n - 1; j++) {
                    temp[i][j + 1] = grid[i][j];
                }
            }

            // Move last element of each row to first of next row
            for (int i = 0; i < m - 1; i++) {
                temp[i + 1][0] = grid[i][n - 1];
            }

            // Move last element of grid to first position
            temp[0][0] = grid[m - 1][n - 1];

            grid = temp;
        }

        return grid;
    }
};