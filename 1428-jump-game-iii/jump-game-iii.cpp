class Solution {
public:
    bool solve(vector<int>& arr, int i, vector<bool>& visited) {
        int n = arr.size();

        // out of bounds
        if (i < 0 || i >= n)
            return false;

        // already visited
        if (visited[i])
            return false;

        // found zero
        if (arr[i] == 0)
            return true;

        visited[i] = true;

        return solve(arr, i + arr[i], visited) ||
               solve(arr, i - arr[i], visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return solve(arr, start, visited);
    }
};