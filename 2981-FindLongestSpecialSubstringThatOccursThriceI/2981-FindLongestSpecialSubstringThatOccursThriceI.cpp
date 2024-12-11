class Solution {
public:
    int maximumLength(string s) {
        int ans = -1;
        map<string,int> m;
        for(int i = 0 ; i < s.size() ;i++){
            for(int j = i ; j < s.size() ;j++){
                if(s[i] != s[j])break;
                string sub = s.substr(i, j - i + 1);
                int len = m[sub] + 1;
                m[sub] ++;
                // cout << sub << " " << len << endl;
                if(len >= 3){
                    ans = max(ans,j - i + 1);
                }
            }
        }
        return ans;
    }
};