// Last updated: 5/10/2025, 11:48:04 PM
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;
        long long cnt1 = 0;
        long long cnt2 = 0;
        for(auto num : nums1) {
            if(num == 0){
                cnt1 ++;
                sum1 += 1;
            } 
            sum1 += num;
        }
        for(auto num : nums2) {
            if(num == 0){
                cnt2 ++;
                sum2 += 1;
            } 
            sum2 += num;
        }
        if(sum1 < sum2 && cnt1 == 0)return -1;
        if(sum2 < sum1 && cnt2 == 0)return -1;
        return max(sum1,sum2);
    }
};