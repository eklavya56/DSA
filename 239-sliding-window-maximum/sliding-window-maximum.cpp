class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> dq; vector<int> r;
        for (int i = 0; i < a.size(); i++) {
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) r.push_back(a[dq.front()]);
        }
        return r;
    }
};
