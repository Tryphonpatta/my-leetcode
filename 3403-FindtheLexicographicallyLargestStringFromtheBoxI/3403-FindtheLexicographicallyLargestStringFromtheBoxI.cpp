// Last updated: 6/4/2025, 10:47:13 PM
class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1)return word;
        string ans;
        for(int i = 0; i < word.size() ; i ++){
            ans = max(ans , word.substr(i, min(word.size() - numFriends + 1, word.size() - i)));
        }
        return ans;
    }
};