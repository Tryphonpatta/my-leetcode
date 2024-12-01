class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> m;
        for(auto a : arr){
            if(a % 2 == 0){
                if(m[a/2])return true;
            }
            if(m[a * 2])return true;
            m[a] = 1;
        }
        return false;
    }
};