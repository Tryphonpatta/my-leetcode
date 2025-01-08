class Solution {
public:
    bool isPrefixOrSuffix(string a, string b) {
        if(a.size() < b.size())return false;
        // cout << a.substr(0,b.size()) << " " << b << (a.substr(0,b.size()) == b) << endl;
        return a.substr(0,b.size()) == b && a.substr(a.size() - b.size(),b.size()) == b;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < words.size() ; i ++){
            for(int j = i + 1 ; j < words.size() ; j++){
                // cout << words[i] << " " << words[j] << endl;
                if(isPrefixOrSuffix(words[j],words[i]))ans++;
            }
        }
        return ans;
    }
};