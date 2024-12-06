class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.length();
        int subLength = n / k;

        unordered_map<string, int> freqS, freqT;

        for (int i = 0; i < n; i += subLength) {
            string sub = s.substr(i, subLength);
            freqS[sub]++;
        }

        for (int i = 0; i < n; i += subLength) {
            string sub = t.substr(i, subLength);
            freqT[sub]++;
        }

        return freqS == freqT;
    }
};