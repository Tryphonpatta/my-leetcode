// Last updated: 4/21/2025, 2:07:52 PM
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        int p=0,ans=0;
        for(long int l=1;l<=n;1){
            if(p<nums.size()&&nums[p]<=l){l+=nums[p];p++;}
            else{ans++;l+=l;}
        }

        return ans;
    }
};