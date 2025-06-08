// Last updated: 6/8/2025, 11:51:10 PM
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int num = 1;
        for(int i = 0; i < n ; i ++){
            ans.push_back(num);
            if (num * 10 <= n) {
                num *= 10;
            }
            else {
                while( num % 10 == 9 || num >= n){
                    num /= 10;
                }
                num ++;
            }
        }
        return ans;
    }
};