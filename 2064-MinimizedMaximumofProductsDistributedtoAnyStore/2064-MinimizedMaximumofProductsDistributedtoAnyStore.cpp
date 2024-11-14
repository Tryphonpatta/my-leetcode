class Solution {
public:
    bool candistribute(vector<int> &v, int k, int n){
        int sum = 0;
        for(int i = 0 ; i < v.size() ; i++){
            sum += (v[i] + k - 1 ) / k;
        }
        // cout << k << ' ' << sum << endl;
        return sum <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 1000000;
        while(l < r){
            int mid = (l + r) / 2;
            // cout << l << " " << mid << " " << r << endl;
            if (candistribute(quantities, mid, n)){
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};