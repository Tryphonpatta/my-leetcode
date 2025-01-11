class Solution {
public:
    bool canConstruct(string s, int k) {
        int c[26] = {};
        if(s.size() < k)return false;
        for(auto ss : s){
            c[ss - 'a']++;
        }
        int odd = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(c[i] % 2)odd ++;
        }
        if(odd > k)return false;
        return true;
    }
};