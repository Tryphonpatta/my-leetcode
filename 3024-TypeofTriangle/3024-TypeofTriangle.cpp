// Last updated: 5/19/2025, 9:09:19 AM
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int sum = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < 3; i++){
            if(nums[i] >= sum - nums[i])return "none";
        }
        if(nums[0] == nums[1] && nums[1] == nums[2])return "equilateral";
        if((nums[0] == nums[1]) || (nums[0] == nums[2]) || (nums[1] == nums[2]))return "isosceles";
        return "scalene";
    }
};