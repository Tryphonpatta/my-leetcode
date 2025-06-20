// Last updated: 6/20/2025, 11:20:38 AM
class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        string ss[4] = {"NE", "NW", "SE", "SW"};
        for (int i = 0; i < 4; i++) {
            int tempk = k;
            int x = 0, y = 0;
            for (auto c : s) {
                if (c == 'S' || c == 'N') {
                    if (c == ss[i][0]) {
                        if (tempk) {
                            tempk--;
                            y++;
                        } else
                            y--;
                    } else
                        y++;
                } else if (c == 'W' || c == 'E') {
                    if (c == ss[i][1]) {
                        if (tempk) {
                            tempk--;
                            x++;
                        } else
                            x--;
                    } else
                        x++;
                }
                ans = max(ans, abs(x) + abs(y));
            }
        }
        return ans;
    }
};