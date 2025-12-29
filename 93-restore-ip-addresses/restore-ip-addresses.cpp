class Solution {
public:
    vector<string> result;

    bool isValid(string s) {
        if (s.size() > 1 && s[0] == '0')
            return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }

    void backtrack(string& s, int index, int parts, string curr) {
        if (parts == 4 && index == s.size()) {
            result.push_back(curr.substr(0, curr.size() - 1));
            return;
        }

        if (parts == 4 || index == s.size())
            return;

        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string part = s.substr(index, len);
            if (isValid(part)) {
                backtrack(s, index + len, parts + 1, curr + part + ".");
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12)
            return result;

        backtrack(s, 0, 0, "");
        return result;
    }
};
