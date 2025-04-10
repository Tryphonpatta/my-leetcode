// Last updated: 4/10/2025, 4:12:33 PM
class Solution {
public:
    bool equalFrequency(string word) {
        int freq[26] = {};
        for(auto c : word){
            freq[c - 'a'] ++;
        }
        bool found = true;
        for(int i = 0; i < 26 ;i++){
            if(freq[i]){
                int val = freq[i]-1;
                set<int> s;
                if(val)s.insert(val);
                for(int j = 0 ; j < 26 ;j ++){
                    if(i == j) continue;
                    if(freq[j]){
                        s.insert(freq[j]);
                    }
                }
                if(s.size() == 1)return true;
            }
        }
        return false;
    }
};