// Last updated: 5/12/2025, 1:36:09 AM
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(auto a : arr) {
            if (a % 2){
                cnt ++;
            }
            else cnt = 0;
            if(cnt >= 3)return true;
        }
        return false;
    }
};