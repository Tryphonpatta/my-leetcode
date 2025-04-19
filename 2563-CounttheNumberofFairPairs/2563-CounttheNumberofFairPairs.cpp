// Last updated: 4/19/2025, 4:35:17 PM
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return lower_bound(nums,upper + 1) - lower_bound(nums,lower);
    }
    long long lower_bound(vector<int>& nums,int value){
        int l = 0,r = nums.size() - 1;
        long long result = 0;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if(sum < value) {
                result += r - l;
                l ++;
            }
            else {
                r --;
            }
        }
        return result;
    }
};