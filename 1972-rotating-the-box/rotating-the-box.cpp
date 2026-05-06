class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // Step 1: Rotate
        vector<vector<char>> rotated(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][m - 1 - i] = box[i][j];
            }
        }

        // Step 2: Apply gravity
        for (int col = 0; col < m; col++) {
            int empty = n - 1;

            for (int row = n - 1; row >= 0; row--) {
                if (rotated[row][col] == '*') {
                    empty = row - 1;
                }
                else if (rotated[row][col] == '#') {
                    rotated[row][col] = '.';
                    rotated[empty][col] = '#';
                    empty--;
                }
            }
        }

        return rotated;
    }
};