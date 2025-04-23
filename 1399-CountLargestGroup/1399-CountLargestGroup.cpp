// Last updated: 4/23/2025, 8:10:48 PM
class Solution {
public:
    int sumOfDigit(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        int a[50] = {};
        int maxCnt = 0;
        for(int i = 1 ; i <= n ; i ++){
            maxCnt = max(maxCnt,++a[sumOfDigit(i)]);
        }
        int ans = 0;
        for(int i = 1 ; i < 50 ;i ++){
            ans += a[i] == maxCnt;
        }
        return ans;
    }
};