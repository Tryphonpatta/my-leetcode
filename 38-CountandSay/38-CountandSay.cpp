// Last updated: 4/18/2025, 9:28:00 AM
class Solution {
public:
    vector<vector<int>> stoa(string s){
        int cnt = 1;
        vector<vector<int>> v;
        for(int i = 0 ; i < s.size() ; i++){
            if(i + 1 >= s.size() || s[i] != s[i + 1]){
                v.push_back({cnt,s[i]});
                cnt = 1;
            }
            else cnt ++;
        }
        return v;
    }
    string atos(vector<vector<int>> v){
        string ans = "";
        for(int i = 0 ; i < v.size() ; i++){
            // cout << v[i][0] << ' ' << v[i][1] << endl;
            ans += char(v[i][0] + '0');
            ans += char(v[i][1] );
        }
        // cout << ans << endl;
        // cout << endl;
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n ; i ++){
            vector<vector<int>> x = stoa(ans);
            ans = atos(x);
        }
        return ans;
    }
};