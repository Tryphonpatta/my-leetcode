// Last updated: 4/13/2025, 5:33:38 PM
class Solution {
public:
    int MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long ans = (fastPower(5,(n + 1)/2) * fastPower(4,(n)/2)) % MOD;
        return ans;
    }
    long long fastPower(long long base, long long power) {
        long long result = 1;
        base %= MOD;

        while (power > 0) {
            if (power % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            power /= 2;
        }
        return result;
    }
};