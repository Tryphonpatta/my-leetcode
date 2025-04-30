// Last updated: 4/30/2025, 12:24:55 PM
class Solution {
public:
    int digit(int n){
        int cnt = 0;
        while(n > 0){
            n /= 10;
            cnt ++;
        }
        return cnt;
    }
    int findNumbers(vector<int>& nums) {
        int ans  = 0;
        for(auto num : nums){
            // cout << digit(num) << endl;
            if((digit(num) & 1) == 0){
                ans ++;
            }
        }
        return ans;
    }
};