class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       int p=0;
       int result=0;
       int n =bank.size();
       for(int  i=0;i<n;i++){
        int c=0;
        for(int j =0;j<bank[i].size();j++){
            if(bank[i][j]=='1') c++;
        }
        if( c==0) continue ;
        result+=p*c;
        p=c;

       }
       return result;
    }
};