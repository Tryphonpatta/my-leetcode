// Last updated: 4/29/2025, 1:16:12 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum = nums[0];
        for(int i = 0; i < nums.size() ; i++){
            maxNum = max(nums[i],maxNum);
        }
        int cnt = 0 ;
        long long ans = 0;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            if(nums[right] == maxNum){
                cnt ++;
            }
            right ++;
            while(cnt >= k){
                ans += nums.size() - right + 1;
                if(nums[left] == maxNum){
                    cnt --;
                }
                left ++;
            }
        }
        return ans;
    }
};