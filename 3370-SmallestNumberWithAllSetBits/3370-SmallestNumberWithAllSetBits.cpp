class Solution {
public:
    int smallestNumber(int n) {
        int exp = 2;
        while(1) {
            if(n <= exp - 1)
                return exp -1;
            exp *= 2;
        }
        return -1;
    }
};