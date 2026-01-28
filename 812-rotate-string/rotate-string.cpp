class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.length()!=goal.length()) return false;
       string temp=s+s;
       int idx=temp.find(goal);
       if (idx!=-1)
       return true;
       else{
        return false;
       } 
    }
};