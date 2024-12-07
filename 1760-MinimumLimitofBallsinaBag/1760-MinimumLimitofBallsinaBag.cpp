class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations, int balls) {
        int sum = 0;
        for (auto num : nums) {
            sum += (num + balls - 1) / balls - 1;
        }
        return sum <= maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = 1e9 + 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if(isPossible(nums,maxOperations,mid)){
                right = mid;
            }
            else left = mid + 1;
        }
        return left;
    }
    
};