// Last updated: 6/6/2025, 3:09:27 PM
class Solution {
public:
    string robotWithString(string s) {
        string ans = "";
        string t = "";
        unordered_map<char,int> count;
        for(auto c : s) {
            count[c] ++;
        } 
        char minCha = 'a';
        for(auto c :s) {
            t.push_back(c);
            count[c]--;
            while (minCha <= 'z' && count[minCha] == 0){
                minCha ++;
            }
            while (!t.empty() && t.back() <= minCha) {
                ans += t.back();
                t.pop_back();
            }
        }
        while (!t.empty()){
            ans += t.back();
            t.pop_back();
        }
        return ans;
    }
};