// Last updated: 7/22/2025, 12:23:49 AM
class Solution {
public:
    string makeFancyString(string s) {
        string ans = "" ;
        int cnt = 1;
        ans.push_back(s[0]);
        for(int i = 1; i < s.size() ; i++){
            if(s[i] == s[i - 1]){
                cnt ++;
            }
            else {
                cnt = 1;
            }
            if(cnt < 3)ans.push_back(s[i]);
        }
        return ans;
    }
};