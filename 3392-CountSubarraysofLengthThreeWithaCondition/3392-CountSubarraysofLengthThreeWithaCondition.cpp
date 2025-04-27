// Last updated: 4/27/2025, 6:03:36 PM
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans =0 ;
        for(int i = 0 ; i < nums.size() - 2; i++){
            if((nums[i] + nums[i + 2]) * 2 == nums[i + 1])ans++;
        }
        return ans;
    }
};