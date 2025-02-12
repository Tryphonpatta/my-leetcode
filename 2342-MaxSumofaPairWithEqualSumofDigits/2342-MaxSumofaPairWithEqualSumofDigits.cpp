class Solution {
public:
    int sumDigit(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> u;
        int ans = -1;
        for(auto n : nums){
            int digit = sumDigit(n);
            if(u[digit] == 0){
                u[digit] = n; 
            }
            else {
                ans = max(ans, n + u[digit]);
                u[digit] = max(u[digit],n);
            }
        }
        return ans;
    }
};