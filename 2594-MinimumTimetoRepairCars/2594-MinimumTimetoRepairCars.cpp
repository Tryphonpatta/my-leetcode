class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long r = 101;
        for(int rank : ranks){
            if(rank < r)r = rank;
        }
        r = r * cars * cars;
        long long l = 0;
        while(l < r){
            long long mid = (l + r + 1) / 2 ;
            long long cnt = 0 ;
            for(int i = 0 ; i < ranks.size() ; i++){
                cnt += sqrt(mid/ranks[i]);
            }
            if(cnt >= cars){
                r = mid - 1;
            }
            else {
                l = mid ;
            }
        }
        return l + 1;
    }
};