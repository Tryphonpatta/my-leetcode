class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l =0,r = 0;
        int ans = 0;
        while(r < nums.size()){
            if(nums[r] - nums[l] <= 2 * k){
                r ++;
            }
            else {
                l ++;
                if(l > r)r ++;
            }
            ans = max(ans , r- l);
        }
        return ans;
    }
};