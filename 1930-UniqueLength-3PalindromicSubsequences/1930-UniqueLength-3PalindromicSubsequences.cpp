class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> pos[27];
        bool vis[27] = {};
        for(int i = 0 ; i < s.size() ; i++){
            pos[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(int index = 0 ;index < 27; index++){
            if(pos[index].size() < 2)continue;
            int f = pos[index][0], l = pos[index].back();
            unordered_set<char> b;
            for(int i = f + 1; i < l ; i++){
                b.insert(s[i]);
            }
            // cout << char(index + 'a') << " " << b.size() << endl;
            ans += b.size();
        }
        return ans;
    }
};