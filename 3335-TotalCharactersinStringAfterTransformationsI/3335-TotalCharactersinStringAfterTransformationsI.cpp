// Last updated: 5/13/2025, 1:24:08 PM
class Solution {
public:
    int m = 1e9 + 7;
    long long int dp[26][100001] = {};
    int count(char a,int k){
        if(dp[a - 'a'][k] != -1)return dp[a -'a'][k];
        if(k == 0)return 1;
        dp[a - 'a'][k] = 1;
        if(a + k > 'z'){
            dp[a - 'a'][k] = count('a', k - 'z' + a - 1) % m + count('b',k - 'z' + a - 1) % m;
        }
        return dp[a - 'a'][k] % m;
    }
    int lengthAfterTransformations(string s, int t) {
        memset(dp,-1,sizeof(dp));
        int ans  = 0;
        for(int i = 0 ; i < s.size() ; i++){
            ans += count(s[i],t) % m;
            ans = ans % m;
        }
        return ans;
    }
};