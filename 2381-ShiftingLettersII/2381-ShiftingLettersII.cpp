class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int d = 0;
        int shift[50002] = {};
        for (auto ss : shifts) {
            if (ss[2] == 0) {
                shift[ss[0]] -= 1;
                shift[ss[1] + 1] += 1;
            }
            else {
                shift[ss[0]] += 1;
                shift[ss[1] + 1] -= 1;
            }
        }
        int index = 0;
        string ans;
        for(int i = 0 ; i < s.size() ; i++){
            d+= shift[i];
            ans += char((((s[i] - 'a' + d) % 26 +26 )% 26) + 'a');
        }
        return ans;
    }
};