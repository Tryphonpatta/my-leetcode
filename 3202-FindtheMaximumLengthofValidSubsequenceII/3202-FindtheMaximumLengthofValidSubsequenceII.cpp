// Last updated: 7/17/2025, 10:07:34 PM
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int dp[1001][1001] = {};
        int ans = 0;
        for(int n : nums){
            n %= k;
            for(int i = 0; i< k;i++){
                dp[i][n] = dp[n][i] + 1;
                ans = max(ans, dp[i][n]);
            }
        }
        return ans;
    }
};