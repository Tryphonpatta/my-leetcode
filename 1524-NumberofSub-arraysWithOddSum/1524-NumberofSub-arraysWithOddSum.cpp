class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddCount = 0 ;
        int evenCount = 1;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < arr.size() ; i++){
            sum += arr[i];
            if(sum % 2 == 0){
                evenCount ++;
                ans += oddCount;
            }
            else {
                oddCount ++;
                ans += evenCount;
            }
            ans %= 1000000007;
        }
        return ans;
    }
};