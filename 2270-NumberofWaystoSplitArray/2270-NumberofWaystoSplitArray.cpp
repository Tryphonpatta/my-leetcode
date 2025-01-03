class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long dp[100002] = {};
        for(int i = 0 ; i < nums.size() ; i++) {
            dp[i] += nums[i];
            dp[i + 1] = dp[i];
        }
        int ans = 0;
        for(int i = 0 ; i < nums.size() - 1 ; i ++){
            if(dp[i] >= dp[nums.size()] - dp[i])
                ans ++;
        }
        return ans;
    }
};