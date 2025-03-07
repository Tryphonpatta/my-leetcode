class Solution {
public:
    bool p[1000001] = {};
    vector<int> closestPrimes(int left, int right) {
        p[1] = true;
        for(int i = 2; i <= sqrt(right) + 1 ; i++){
            if(p[i])continue;
            for(int j = i * i ; j <= right ; j += i){
                p[j] = 1;
            }
        }
        int diff = 100001;
        int a = -1;
        vector<int> ans;
        for(int i = left ; i <= right ; i ++){
            if(p[i])continue;
            if(a == -1)a = i;
            else {
                if ( i - a < diff) {
                    ans = {a,i};
                    diff = i - a;
                }
                a = i;
            }
        }
        if(ans.size() <= 1)return {-1, -1};
        return ans;
    }
};