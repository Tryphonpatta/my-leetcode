// Last updated: 4/28/2025, 5:24:29 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        long long cnt = 0;
        int left = 0; 
        int right = 0;
        while(right < nums.size()) {
            sum += nums[right];
            while(left <= right && sum * (right - left + 1) >= k ) {
                sum -= nums[left];
                left ++;
            }
            cnt += right - left + 1;
            right ++;
        }
        return cnt;
    }
};