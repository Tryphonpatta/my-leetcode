class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int l = 0 ; 
        int r = arr.size() - 1 ;
        arr.push_back(INT_MAX);
        for(int i = arr.size() - 1  ; i >= 1 ; i--){
            if(arr[i - 1] <= arr[i]){
                r = i - 1;
            }
            else break;
        }
        if(r == 0)
            return 0;
        int temp = r;
        int ans = r;
        cout << r;
        while (l < r && r < arr.size()) {
            if(arr[l] <= arr[r] && (l == 0 || arr[l] >= arr[l - 1])){
                ans = min(ans, r - l - 1);
                l ++;
            }
            else {
                r ++;
            }
        }
        return ans ;
    }
};