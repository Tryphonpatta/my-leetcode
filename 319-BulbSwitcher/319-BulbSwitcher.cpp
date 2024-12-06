class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        for(int i = 2; i <= n ; i ++){
            if(i * i > n)return i -1;
        }
        return n;
    }
};