// Last updated: 5/3/2025, 8:04:21 PM
class Solution {
public:
    int getAns(vector<int>& tops, vector<int>& bottoms,int target){
        int top = 0;
        int bot = 0;
        for(int i = 0 ; i < tops.size() ;i++){
            if(tops[i] != target && bottoms[i] != target)return INT_MAX;
            if(tops[i] != target) top ++;
            if(bottoms[i] != target) bot ++;
        }
        return min(top,bot);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = min(getAns(tops,bottoms,tops[0]),getAns(tops,bottoms,bottoms[0]));
        return ans == INT_MAX ? -1 : ans;
    }
};