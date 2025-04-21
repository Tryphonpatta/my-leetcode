// Last updated: 4/21/2025, 9:43:03 AM
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int minDiff = differences[0];
        int minSum = 0;
        int maxDiff = differences[0];
        int maxSum =  0;
        int dif = 0;
        for(auto diff : differences){
            minSum += diff;
            maxSum += diff;
            dif += diff;
            minDiff = min(minSum,minDiff);
            maxDiff = max(maxSum,maxDiff);
            if(minSum > 0){
                minSum = 0;
            }
            if(maxSum < 0)maxSum = 0;
            if(abs(minSum) > upper - lower + 1)return 0;
            if(maxSum > upper - lower + 1)return 0;
        }
        return (upper - lower + 1 - max(abs(minDiff),maxDiff));
    }
};