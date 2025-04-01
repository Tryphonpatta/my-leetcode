// Last updated: 4/1/2025, 4:57:36 PM
class Solution {
public:
    long long dp[100001] = {};
    long long rec(int i,int n, vector<vector<int>>& q){
        if(i >= n)return 0;
        if(dp[i] != -1)return dp[i];
        dp[i] = max(rec(i + 1,n ,q), rec(i + q[i][1] + 1,n , q) + q[i][0]);
        return dp[i];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        rec(0,questions.size(),questions);
        return dp[0];
    }
};