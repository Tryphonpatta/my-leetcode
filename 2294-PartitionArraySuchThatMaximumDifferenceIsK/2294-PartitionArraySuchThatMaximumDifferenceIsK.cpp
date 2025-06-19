// Last updated: 6/19/2025, 11:15:21 PM
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans = 1;
        sort(nums.begin(),nums.end());
        int m = nums[0];
        for(int i = 1 ;i < nums.size() ; i++){
            if(nums[i] - m > k){
                // cout << nums[i] << " "  << m << endl;
                ans ++;
                m = nums[i];
            }
        }
        return ans;
    }
};