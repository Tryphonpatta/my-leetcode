class Solution {
public:
    int ans =0;
    int rec(int i , int sum , int target,vector<int>& nums){
        if(i >= nums.size()){
            if(target == sum)ans ++;
            return 0;
        }
        rec(i + 1, sum + nums[i],target,nums);
        rec(i + 1, sum - nums[i],target,nums);
        return 0;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        rec(0,0,target,nums);
        return ans;
    }
};