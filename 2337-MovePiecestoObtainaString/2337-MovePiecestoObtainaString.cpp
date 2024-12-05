class Solution {
public:
    bool canChange(string start, string target) {
        vector<pair<int, int>> s, t;
        for (int i = 0; i < start.size(); i++) {
            char st = start[i];
            if (st != '_') {
                s.push_back({st, i});
            }
        }
        for (int i = 0; i < target.size(); i++) {
            char st = target[i];
            if (st != '_') {
                t.push_back({st, i});
            }
        }
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i].first != t[i].first)
                return false;
            if (s[i].first == 'R') {
                if (s[i].second > t[i].second)
                    return false;
            } else {
                if (s[i].second < t[i].second)
                    return false;
            }
        }
        return true;
    }
};