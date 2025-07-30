// Last updated: 7/30/2025, 3:45:31 PM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 1;
        int ma = nums[0];
        int temp = 1;
        int k = nums[0];
        for(int i = 1 ;  i < nums.size() ;i++)
        {
            if(nums[i] == ma && nums[i] == nums[i-1])
            {
                temp++;
                ans = max(temp,ans);
                continue;
            }
            if(nums[i] > ma)
            {
                ma = nums[i];
                temp = 1;
                ans = temp;
                continue;
            }
            if(nums[i] == ma)
            {
                temp = 1;
                continue;
            }
            temp = 0;
        }
        return ans;
    }
};