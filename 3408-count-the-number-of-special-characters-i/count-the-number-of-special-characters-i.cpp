class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            bool small = false;
            bool capital = false;
            // poore word ko traverse karo
            for(int i = 0; i < word.size(); i++) {
                // small letter mila
                if(word[i] == ch) {
                    small = true;
                }
                // capital letter mila
                if(word[i] == ch - 32) {
                    capital = true;
                }
            }
            // dono present hain
            if(small && capital) {
                cnt++;
            }
        }
        return cnt;
    }
};