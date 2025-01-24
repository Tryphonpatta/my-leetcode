class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0 ;
        int right = nums.size() - 1;
        int pivot = (left + right) / 2;
        while(left <= right){
            pivot = (left + right) / 2;
            // cout << pivot << endl;
            if(nums[pivot] > nums.back()){
                left = pivot + 1;
            }
            else {
                right = pivot - 1;
            }
        }
        pivot = left;
        left = 0;
        right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[(mid + pivot) % nums.size()] == target)return (mid + pivot) % nums.size();
            if(nums[(mid + pivot) % nums.size()] < target){
                left = mid + 1;
            }
            else {
                right = mid -  1;
            }
        }
        // cout << pivot;
        return -1;
    }
};