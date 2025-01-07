class Solution {
public:
    bool isSub(string a,string b){
        if(a.size() < b.size())return false;
        for(int i = 0 ; i < a.size() - b.size() + 1; i++){
            if(b == a.substr(i,b.size()))return true;
        }
        return false;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i = 0 ; i < words.size() ; i++){
            for(int j = 0; j < words.size() ; j++){
                if(i == j)continue;
                if(isSub(words[j],words[i])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};