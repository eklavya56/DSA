class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) {  // extracts words ignoring spaces
            words.push_back(word);
        }
        reverse(words.begin(), words.end());
        string result;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) result += " ";
            result += words[i];
        }
        return result;
    }
};
