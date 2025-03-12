class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int target=0;
        int pos=-1;
        int neg=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<0)
            {
                neg=mid;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        left=0;
        right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>0)
            {
                pos=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        int n=nums.size();
        if(pos==-1 && neg==-1)
        {
            return 0;
        }
        else if(pos==-1)
        {
            return neg+1;
        }
        else if(neg==-1)
        {
            return n-pos;
        }
        else
        {
            return max(n-pos,neg+1);
        }

    }

};