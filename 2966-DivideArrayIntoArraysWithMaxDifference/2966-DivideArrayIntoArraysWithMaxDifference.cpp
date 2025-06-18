// Last updated: 6/18/2025, 7:29:41 PM
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans(nums.size() / 3, vector<int>{});
        for(int i = 0; i < nums.size() ;i++){
            if(ans[i/3].size() > 0 && nums[i] - ans[i/3][0] > k)return {};
            ans[i/3].push_back(nums[i]);
        }
        return ans;
    }
};