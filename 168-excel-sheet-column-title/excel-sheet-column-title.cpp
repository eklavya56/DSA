class Solution {
public:
    string convertToTitle(int col) {
        string ans;
        while(col>0){
            col--;
            int r=col%26;
            ans.push_back(r + 'A');
            col=col/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};