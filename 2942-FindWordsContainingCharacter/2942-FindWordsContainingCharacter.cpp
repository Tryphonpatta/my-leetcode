// Last updated: 5/24/2025, 2:33:52 PM
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i = 0 ; i < words.size() ; i++){
            for(auto b : words[i]){
                if(b == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};