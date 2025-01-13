class Solution {
public:
    int minimumLength(string s) {
        int cnt[26] = {};
        int k[10] = {1,1,2,1,2,1,2,1,2,0};
        int ans =0;
        for(int i = 0; i < s.size() ; i++){
            cnt[s[i] - 'a'] ++;
        }
        for(int i = 0 ; i < 26 ; i ++) {
            if(cnt[i] > 0)
            ans += (cnt[i] + 1) % 2 + 1;
        }
        return ans;
    }
};