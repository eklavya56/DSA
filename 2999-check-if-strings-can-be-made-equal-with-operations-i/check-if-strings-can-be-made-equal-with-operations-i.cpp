class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        if (s1 == s2) return true;

        // swap (0,2)
        swap(s1[0], s1[2]);
        if (s1 == s2) return true;

        // revert and try (1,3)
        swap(s1[0], s1[2]);
        swap(s1[1], s1[3]);
        if (s1 == s2) return true;

        // try both swaps
        swap(s1[0], s1[2]);
        if (s1 == s2) return true;

        return false;
    }
};