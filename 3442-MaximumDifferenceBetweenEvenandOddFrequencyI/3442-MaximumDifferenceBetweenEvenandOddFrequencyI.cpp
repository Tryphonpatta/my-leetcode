// Last updated: 6/11/2025, 2:46:14 AM
class Solution {
public:
    int maxDifference(string s) {
        int c[26] = {};
        for(auto ch : s){
            c[ch - 'a'] ++;
        }
        int maxOdd = 1, minEven = s.size();
        for (int i = 0; i < 26;i ++) {
            if(!c[i])continue;
            if (c[i] % 2 == 1) {
                maxOdd = max(maxOdd, c[i]);
            } else {
                minEven = min(minEven, c[i]);
            }
        }
        return maxOdd - minEven;
    }
};