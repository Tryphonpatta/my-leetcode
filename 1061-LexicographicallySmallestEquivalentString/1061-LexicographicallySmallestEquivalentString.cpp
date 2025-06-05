// Last updated: 6/5/2025, 11:23:29 AM
class Solution {
public:
    int root[300] = {};
    int find(int a) {
        if (root[a] != a && root[a] != 0)
            return root[a] = find(root[a]);
        return a;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < s1.size(); i++) {
            if (!root[s1[i]] && !root[s2[i]]) {
                if (s1[i] < s2[i]) {
                    root[s2[i]] = s1[i];
                } else {
                    root[s1[i]] = s2[i];
                }
            }
            else {
                if (find(s1[i]) < find(s2[i])) {
                    root[find(s2[i])] = find(s1[i]);
                } else {
                    root[find(s1[i])] = find(s2[i]);
                }
            }
        }
        string ans;
        // for(int i = 'a' ; i <= 'z' ;i++){
        //     cout << char(i) << " : " << char(root[i]) << endl;
        // }
        for (int i = 0; i < baseStr.size(); i++) {
            if (find(root[baseStr[i]]) == 0)
                ans += baseStr[i];
            else {
                ans += find(root[baseStr[i]]);
            }
        }
        return ans;
    }
};