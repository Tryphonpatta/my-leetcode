class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum = 0;
        int maxSum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size() ;i++){
            ans = max(maxSum,max(-minSum,ans));
            minSum += nums[i];
            maxSum += nums[i];
            if(minSum >= 0)minSum =0;
            if(maxSum <= 0)maxSum = 0; 
        }
        ans = max(maxSum,max(-minSum,ans));
        return ans;
    }
};