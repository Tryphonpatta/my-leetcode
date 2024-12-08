class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        map<int, int> maxAfter;
        int n = events.size();
        maxAfter[events[n - 1][0]] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            maxAfter[events[i][0]] = max(events[i][2], maxAfter[events[i + 1][0]]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, events[i][2]);
            auto it = maxAfter.upper_bound(events[i][1]);
            if (it != maxAfter.end()) {
                ans = max(ans, events[i][2] + it->second);
            }
        }

        return ans;
    }
};