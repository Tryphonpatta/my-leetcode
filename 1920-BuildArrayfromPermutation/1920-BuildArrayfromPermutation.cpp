// Last updated: 5/6/2025, 12:10:47 PM
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(auto num : nums)ans.push_back(nums[num]);
        return ans;
    }
};