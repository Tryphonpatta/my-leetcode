class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1)return 1;
        long long  mul = 4;
        long long  ans = 0;
        for(int i = 0; i< n - 1;i++){
            ans += mul;
            mul += 4;
        }
        return ans + 1;
    }
};