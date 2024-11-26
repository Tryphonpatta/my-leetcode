class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int degreeIn[101] = {};
        int degreeOut[101] = {};
        for(auto edge : edges) {
            degreeIn[edge[1]]++;
        }
        int ans = -1;
        for(int i = 0; i < n ; i++){
            // cout << degreeIn[i] << endl;
            if(degreeIn[i] == 0){
                if(ans == -1){
                    ans = i;
                }
                else return -1;
            }
        }
        return ans;
    }
};