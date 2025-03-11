class Solution {
public:
    int numberOfSubstrings(string s) {
        int c[300] = {};
        int left =0, right =0;
        int ans = 0;
        while(right < s.size()) {
            while((!c['a'] || !c['b'] || !c['c']) && right < s.size()){
                c[s[right]]++;
                right ++;
            }
            while (c['a'] && c['b'] && c['c']){
                c[s[left]]--;
                left ++;
                ans += s.size() - right + 1;
            }
        }
        return ans;
    }
};