// Last updated: 7/5/2025, 11:12:25 AM
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[501] = {};
        for(auto a : arr){
            freq[a] ++;
        }
        int ans = -1;
        for(int i= 1 ;i <= 500; i++){
            if(freq[i] == i){
                ans = max(ans,i);
            }
        }
        return ans;
    }
};