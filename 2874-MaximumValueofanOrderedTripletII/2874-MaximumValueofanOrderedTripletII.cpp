// Last updated: 4/3/2025, 9:10:11 AM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int maxFromStart[100001] = {};
        // int minFromLeft[100001] = {};
        int maxFromLeft[100001] = {};
        maxFromStart[0] = nums[0];
        // minFromLeft[nums.size() - 1] = nums.back();
        maxFromLeft[nums.size() - 1] = nums.back();
        for(int i = 1; i < nums.size() ;i++){
            maxFromStart[i] = max(maxFromStart[i - 1],nums[i]);
            maxFromLeft[nums.size() - i - 1] = max(nums[nums.size() - i - 1],maxFromLeft[nums.size() - i]);
            // minFromLeft[nums.size() - i - 1] = min(nums[nums.size() - i - 1],minFromLeft[nums.size() - i]);
        }
        long long ans = 0;
        for(int i = 1 ; i < nums.size() - 1 ; i ++){
            // ans = max(ans,(maxFromStart[i - 1] - nums[i]) * maxFromLeft[i + 1]);
            long long cal = (long long)(maxFromStart[i - 1] - nums[i]) * maxFromLeft[i + 1];
            if (cal > ans) ans = cal;
        }
        return ans;
    }
};