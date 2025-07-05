// Last updated: 7/5/2025, 11:17:08 AM
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.size();
        int curr = 0;
        while (curr < n) {
            res.push_back(s.substr(curr, k));
            curr += k;
        }
        res.back() += string(k - res.back().length(), fill);
        return res;
    }
};