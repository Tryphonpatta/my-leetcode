class Solution {
public:
    int minChanges(string s) {
        char cur = s[0];
        int cnt = 1;
        int ans  = 0;
        for(int i = 1 ; i < s.size() ; i++){
            if(s[i] == cur || cnt == 0){
                cnt ++;
                cur =  s[i];
            }
            else {
                ans ++;
                cnt = 0;
                cur = s[i];
            }
            if (cnt % 2 == 0)
            {
                cnt = 0;
            }
        }
        return ans;
    }
    
};