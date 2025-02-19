class Solution {
public:
    char c[3] = {'a', 'b', 'c'};
    vector<string> ans;
    void rec(string s, int n){
        if(s.size() == n){
            ans.push_back(s);
            return;
        };
        if(s.size() >= n)return ;
        for(int i = 0 ; i < 3 ; i ++){
            if(s[s.size() - 1] != c[i])rec(s + c[i], n);
        }
        return;
        
    }
    string getHappyString(int n, int k) {
        rec("a",n);
        rec("b",n);
        rec("c",n);
        if(ans.size() < k)return "";
        return ans[k - 1];
    }
};