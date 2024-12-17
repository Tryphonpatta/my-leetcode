class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>> pq;
        int cnt[26] = {};
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                // cout << char('a' + i) << " " << cnt[i] << endl;
                pq.push({'a' + i, cnt[i]});
            }
        }
        string ans = "";
        while (!pq.empty()) {
            char x = pq.top().first;
            int y = pq.top().second;
            // cout << x << y << endl;
            pq.pop();
            if(ans.size() == 0 || x != ans.back()){
                for (int j = 1; j <= y && j <= repeatLimit; j++) {
                    ans += x;
                }
                y = max(0, y - repeatLimit);
            }
             else {
                if (pq.empty())
                    continue;
                char xx = pq.top().first;
                int yy = pq.top().second;
                pq.pop();
                ans += xx;
                yy --;
                if (yy > 0) {
                    pq.push({xx, yy});
                }
            }
            if (y > 0) {
                pq.push({x, y});
            }
        }
        return ans;
    }
};