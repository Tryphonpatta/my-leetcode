// Last updated: 3/26/2025, 12:42:35 AM
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> horizon, vertical;
        for (auto rect : rectangles) {
            vertical.push_back({rect[0], rect[2]});
            horizon.push_back({rect[1], rect[3]});
        }
        sort(vertical.begin(), vertical.end());
        sort(horizon.begin(), horizon.end());
        int m = 0;
        int cnt = 0;
        for (int i = 0; i < horizon.size() - 1; i++) {
            pair<int, int> currentBox = horizon[i];
            pair<int, int> nextBox = horizon[i + 1];
            // cout << "(" << currentBox.first << " " << currentBox.second << ") ";
            m = max(m, currentBox.second);
            if (m <= nextBox.first) {
                cnt++;
            }
        }
        // cout << endl << cnt << endl;
        if (cnt >= 2)
            return true;
        cnt = 0;
        m = 0;
        for (int i = 0; i < vertical.size() - 1; i++) {
            pair<int, int> currentBox = vertical[i];
            // cout << "(" << currentBox.first << " " << currentBox.second << ") ";
            pair<int, int> nextBox = vertical[i + 1];
            m = max(m, currentBox.second);
            if (m <= nextBox.first) {
                cnt++;
            }
        }
        // cout << endl << cnt << endl;
        if (cnt >= 2)
            return true;
        return false;
    }
};