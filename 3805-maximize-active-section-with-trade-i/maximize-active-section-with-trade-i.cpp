class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        // Count initial active sections (1's)
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        // Add 1 at both ends
        s = "1" + s + "1";

        int maxGain = 0;

        for (int i = 1; i < s.size() - 1;) {

            // Find a block of 1's
            if (s[i] == '1') {
                int start = i;

                while (i < s.size() && s[i] == '1')
                    i++;

                int end = i - 1;

                // Check if this block is surrounded by 0's
                if (s[start - 1] == '0' && s[end + 1] == '0') {

                    int left = 0;
                    int j = start - 1;
                    while (j >= 0 && s[j] == '0') {
                        left++;
                        j--;
                    }

                    int right = 0;
                    j = end + 1;
                    while (j < s.size() && s[j] == '0') {
                        right++;
                        j++;
                    }

                    maxGain = max(maxGain, left + right);
                }
            }
            else {
                i++;
            }
        }

        return ones + maxGain;
    }
};