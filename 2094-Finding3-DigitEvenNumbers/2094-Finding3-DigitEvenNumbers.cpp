// Last updated: 5/12/2025, 3:07:11 PM
class Solution {
public:
    int c[10] = {};
    bool check(int n){
        int cnt[10] = {};
        while(n > 0){
            cnt[n % 10] ++;
            n = n / 10;
        }
        for(int i = 0; i <= 9;i++){
            if(cnt[i] > c[i])return false;
        }
        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        for(auto d : digits) {
            c[d] ++;
        }
        vector<int> ans;
        for(int i = 100; i <= 999 ;i+=2){
            if(check(i))ans.push_back(i);
        }
        return ans;
    }
};