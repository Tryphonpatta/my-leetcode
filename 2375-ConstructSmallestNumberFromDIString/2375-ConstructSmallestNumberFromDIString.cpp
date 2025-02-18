class Solution {
public:
    int a[10] = {};
    int dp[10] = {};
    string smallestNumber(string pattern) {
        dp[pattern.size() - 1] = pattern[pattern.size() - 1] == 'D' ? 1 : 0;
        for (int i = pattern.size() - 2; i >= 0; i--) {
            if (pattern[i] == 'D') {
                dp[i] += dp[i + 1] + 1;
            }
        }
        string ans;
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 'I') {
                int x = 1;
                while (a[x]) {
                    x++;
                }
                a[x] = 1;
                ans += to_string(x);
            } else {
                int x = 1;
                while (a[x]) {
                    x++;
                }
                x = x + dp[i];
                a[x] = 1;
                ans += to_string(x);
            }
        }
        int x = 1;
        while (a[x]) {
            x++;
        }
        a[x] = 1;
        ans += to_string(x);
        return ans;
    }
};