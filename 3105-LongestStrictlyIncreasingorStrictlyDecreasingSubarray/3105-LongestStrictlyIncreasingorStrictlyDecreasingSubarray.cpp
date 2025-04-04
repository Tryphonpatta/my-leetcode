class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;
        int ans = 1;
        for(int i = 1 ; i < nums.size() ;i++){
            if(nums[i - 1] < nums[i]){
                inc ++;
            }
            else {
                inc = 1;
            }
            if(nums[i - 1] > nums[i]){
                dec ++;
            }
            else {
                dec = 1;
            }
            ans = max(ans,max(inc,dec));
        }
        return ans;
    }
};