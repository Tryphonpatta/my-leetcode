class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int a[26] = {};
        for (int i = 0; i < words2.size(); i++) {
            int k[26] = {};
            for(auto w : words2[i])
                k[w - 'a'] ++;
            for(int j=0;j <26;j++){
                a[j] = max(a[j],k[j]);
            }
        }
        vector<string> ans;
        for(int i = 0 ; i < words1.size() ;i++){
            int b[26] = {};
            bool pass = true;
            for(auto w : words1[i])
                b[w - 'a'] ++;
            for(int j = 0 ; j < 26 ; j++){
                if(b[j] < a[j]){
                    pass =false;
                    break;
                }
            }
            if(pass)ans.push_back(words1[i]);
        }
        return ans;
    }
};