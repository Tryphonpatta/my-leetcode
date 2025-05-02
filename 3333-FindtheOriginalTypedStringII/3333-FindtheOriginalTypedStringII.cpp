// Last updated: 5/2/2025, 9:34:40 AM
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long ans = 0;
        long long prefix = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            prefix += nums[i];
            ans = max(ans, (prefix + i) / (i + 1));
        }
        return ans;
    }
};