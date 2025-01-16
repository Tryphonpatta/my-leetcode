class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
      if(nums2.size() % 2 == 0 && nums1.size() % 2 == 0)return 0;
      int a = 0;
      if(nums2.size() % 2){
        for(int num : nums1){
            a = a ^ num;
        }
      }
      if(nums1.size() % 2){
        for(int num : nums2){
            a = a ^ num;
        }
      }
      return a;
    }
};