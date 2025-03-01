class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans(nums.size());
        int index = 0;
        for(int i = 0 ; i < nums.size() - 1 ; i ++){
            if(nums[i] == 0)continue;
            if(nums[i] == nums[i + 1]){
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            ans[index] = nums[i];
            index ++;
        }
        if(nums.back())ans[index] = nums.back();
        return ans;
    }
};