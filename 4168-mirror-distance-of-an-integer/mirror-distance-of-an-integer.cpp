class Solution {
public:
    int reverseInteger(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int x = reverseInteger(n);
        int ans = abs(n - x);
        return ans;
    }
};