class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int k[51] = {};
        vector<int> ans;
        int cnt = 0;
        for(int i = 0 ; i < A.size() ; i++){
            if(++k[A[i]] == 2){
                cnt ++;
            }
            if(++k[B[i]] == 2)cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};