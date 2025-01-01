class Solution {
public:
    int maxScore(string s) {
        int o[502] = {};
        int z[502] = {};
        for(int i = s.size() - 1; i >= 0 ; i --){
            o[i] = s[i] == '1' ? o[i + 1] + 1 : o[i + 1];
        }
        z[0] = s[0] == '0' ? 1 : 0;
        int ans = z[0] + o[1];
        for(int i = 1 ; i < s.size() - 1 ; i++){
            z[i] = s[i] == '0' ? z[i - 1] + 1 : z[i - 1];
            // cout << "z : " << z[i] << " o : " << o[i] << endl;
            ans = max(ans, z[i] + o[i + 1]);
        }
        return ans;
    }
};