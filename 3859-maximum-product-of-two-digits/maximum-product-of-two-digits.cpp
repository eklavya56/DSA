class Solution {
public:
    int maxProduct(int n) {
        int current_max = n % 10;
        n /= 10;

        int result = 0;

        while (n > 0) {
            int digit = n % 10;
            result = max(result, digit * current_max);
            current_max = max(current_max, digit);
            n /= 10;
        }

        return result;
    }
};