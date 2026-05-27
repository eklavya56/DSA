class Solution {
public:
    int numberOfSpecialChars(string word) {

        int cnt = 0;

        for(char ch = 'a'; ch <= 'z'; ch++) {

            int lastSmall = -1;
            int firstCapital = -1;

            for(int i = 0; i < word.size(); i++) {

                // lowercase position
                if(word[i] == ch) {
                    lastSmall = i;
                }

                // first uppercase position
                if(word[i] == ch - 32) {

                    if(firstCapital == -1) {
                        firstCapital = i;
                    }
                }
            }

            // dono hone chahiye
            // aur lowercase pehle aana chahiye
            if(lastSmall != -1 &&
               firstCapital != -1 &&
               lastSmall < firstCapital) {

                cnt++;
            }
        }

        return cnt;
    }
};