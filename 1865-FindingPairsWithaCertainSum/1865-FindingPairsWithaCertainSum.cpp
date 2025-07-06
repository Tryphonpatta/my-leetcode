// Last updated: 7/6/2025, 1:37:19 PM
class FindSumPairs {
public:
    vector<int> n1, n2;
    unordered_map<int, int> m2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (auto n : n2) {
            m2[n]++;
        }
    }

    void add(int index, int val) {
        m2[n2[index]]--;
        m2[n2[index] + val]++;
        n2[index] += val;
    }

    int count(int tot) {
        int ans = 0;
        for (auto n : n1) {
            // if(m2[tot - n]){
            ans += m2[tot - n];
            // }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */