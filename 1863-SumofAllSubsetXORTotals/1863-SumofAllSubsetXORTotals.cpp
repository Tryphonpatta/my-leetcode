// Last updated: 4/6/2025, 1:27:27 AM
class Solution {
private:
    int dfs(vector<int>& nums, int index, int currXOR) {
        if (index == nums.size()) {
            return currXOR;
        }
        // Include current element
        int take = dfs(nums, index + 1, currXOR ^ nums[index]);
        // Exclude current element
        int notTake = dfs(nums, index + 1, currXOR);
        return take + notTake;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};
