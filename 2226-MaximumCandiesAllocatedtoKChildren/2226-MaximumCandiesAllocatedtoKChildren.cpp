class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l= 0,r;
        for(auto candy : candies)r = max(r,candy);
        while(l < r) {
            int mid = (l + r + 1) / 2;
            long long cnt = 0;
            for(auto candy: candies) {
                cnt += candy / mid;
            }
            if(cnt >= k){
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        return l;
    }
};