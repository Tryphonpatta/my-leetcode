// Last updated: 5/20/2025, 2:54:34 PM
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int diff[100100] = {};
        for(int i = 0 ; i < queries.size() ; i++){
            diff[queries[i][0]] ++;
            diff[queries[i][1] + 1] --;
        }
        int cur = 0;
        for(int i = 0; i < nums.size() ; i++){
            cur += diff[i];
            nums[i] -= cur;
            if(nums[i] > 0)
                return false;
        }
        return true;
    }
};