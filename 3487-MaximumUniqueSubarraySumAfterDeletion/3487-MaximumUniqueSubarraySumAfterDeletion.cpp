// Last updated: 7/25/2025, 9:45:12 AM
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,bool> h;
        int m = INT_MIN;
        int cnt = 0;
        int sum = 0;
        for(auto n : nums){
            m = max(m,n);
            if (n > 0 && h[n] == 0){
                h[n] = 1;
                sum += n;
                cnt ++;
            }
        }
        return cnt ? sum : m;
    }
};