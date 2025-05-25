// Last updated: 5/25/2025, 3:40:17 PM
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        bool c[300][300] = {};
        vector<string> s;
        for(auto w : words) {
            if(w[0] < w[1]){
                if(c[w[0]][w[1]] == 0)
                    s.push_back({w[0],w[1]});
                c[w[0]][w[1]] = 1;
            }
            else {
                if(c[w[1]][w[0]] == 0)
                    s.push_back({w[1],w[0]});
                c[w[1]][w[0]] = 1;
            }
            m[w] ++;
        }
        int ans = 0;
        int middle = 0;
        for(auto w : s){
            if(w[1] == w[0]){
                int x = m[{w[0],w[1]}];
                if(x >= 2){
                    ans += ((m[{w[0],w[1]}])/2)*2*2;
                }
                if(x % 2){
                    middle = 2; 
                }
                continue;
            }
            ans += min(m[{w[1],w[0]}],m[{w[0],w[1]}]) * 4;
        }
        return ans + middle;
    }
};