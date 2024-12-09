class Solution {
public:
    int dp[100001] = { };
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int x = 0;
        dp[0] = x;
        for(int i = 1 ; i < nums.size() ; i++) {
            if(nums[i - 1] % 2 == nums[i] % 2)
            {
                x ++;
            }
            dp[i] = x;
        }
        vector<bool> ans;
        for(int i = 0; i < queries.size() ;i++){
            ans.push_back({dp[queries[i][0]] == dp[queries[i][1]]});
        }
        return ans;
    }
};