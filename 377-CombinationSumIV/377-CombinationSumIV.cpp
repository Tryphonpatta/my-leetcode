// Last updated: 5/9/2025, 9:32:28 AM
class Solution {
public:
    int dp[1001] = {};
    int rec(int n,vector<int>& nums) {
        if(n == 0)return 1;
        if(n < 0)return 0;
        if(dp[n] != -1)return dp[n];
        int cnt = 0;
        for(int i = 0; i < nums.size() ;i ++){
            cnt += rec(n - nums[i],nums);
        }
        return dp[n] = cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return rec(target,nums);
    }
};