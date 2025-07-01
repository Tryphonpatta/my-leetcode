// Last updated: 7/1/2025, 9:02:30 AM
class Solution {
public:
    int possibleStringCount(string word) {
        // int cnt = 1;
        int ans = 1;
        for(int i = 1; i< word.size() ; i++){
            if(word[i] == word[i - 1])ans ++;
            // else {
            //     ans += cnt - 1;
            //     cnt = 1;
            // }
        }
        return ans;

    }
};