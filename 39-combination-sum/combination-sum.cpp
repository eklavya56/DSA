class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& c, int t, int i, vector<int>& path) {
        if (t == 0) { ans.push_back(path); return; }
        if (i == c.size() || t < 0) return;
        path.push_back(c[i]);
        dfs(c, t - c[i], i, path);   // use same element
        path.pop_back();
        dfs(c, t, i + 1, path);      // skip to next
    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int> path;
        dfs(c, t, 0, path);
        return ans;
    }
};
