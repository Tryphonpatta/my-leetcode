class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> miss;
        for(int i = 0; i < s1.size() ; i++){
            if(s1[i] != s2[i])miss.push_back(i);
        }
        if(miss.size() == 0)return true;
        if(miss.size() != 2)return false;
        if(s1[miss[0]] == s2[miss[1]] && s2[miss[0]] == s1[miss[1]])return true;
        return false;
    }
};