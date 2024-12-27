class Solution {
public:
    int memo[101][101]= {};
    int dp(string s,int l,int r){
        if(l > r)return 0;
        if(memo[l][r] > 0)return memo[l][r];
        int lOrg = l;
        while(l + 1 <= r && s[l] == s[l + 1]){
            l ++;
        }
        int ans = 1 + dp(s,l + 1,r);
        for(int m = l + 1; m<=r;++m){
            if(s[l] == s[m]) {
                ans = min(ans,dp(s,l + 1, m - 1) + dp(s,m,r));
            }
        }
        return memo[lOrg][r] = ans;
    }
    int strangePrinter(string s) {
        return dp(s,0,s.size() - 1);
    }
};