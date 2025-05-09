// Last updated: 5/9/2025, 9:21:23 AM
class Solution {
public:
    int MOD = 1e9 + 7;
    int countBalancedPermutations(string num) {
        int total = 0;
        int n = num.size();
        int cnt[10] = {};
        for (auto cha : num) {
            cnt[cha - '0']++;
            total += cha - '0';
        }
        if (total % 2)
            return 0;
        int target = total / 2;
        int maxOdd = (n + 1) / 2;
        long long comb[42][42] = {};
        long long f[900][42] = {};
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }
        f[0][0] = 1;
        int psum = 0, totSum = 0;
        for (int i = 0; i <= 9; i++) {
            psum += cnt[i];
            totSum += i * cnt[i];
            for (int oddCnt = min(psum, maxOdd);
                 oddCnt >= max(0, psum - (n - maxOdd)); oddCnt--) {
                int evenCnt = psum - oddCnt;
                for (int curr = min(totSum, target);
                     curr >= max(0, totSum - target); curr--) {
                    long long res = 0;
                    for (int j = max(0, cnt[i] - evenCnt);
                         j <= min(cnt[i], oddCnt) && i * j <= curr; j++) {
                        long long ways =
                            comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                        res = (res + ways * f[curr - i * j][oddCnt - j] % MOD) %
                              MOD;
                    }
                    f[curr][oddCnt] = res % MOD;
                }
            }
        }

        return f[target][maxOdd];
    }
};