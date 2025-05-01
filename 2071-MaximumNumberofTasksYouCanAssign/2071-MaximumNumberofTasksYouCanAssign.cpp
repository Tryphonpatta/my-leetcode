// Last updated: 5/1/2025, 8:08:07 PM
class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());

        int left = 0, right = min(tasks.size(),workers.size());
        while(left < right){
            int mid = (left + right + 1 ) /2 ;
            int p = 0;
            multiset<int> w(workers.end() - mid, workers.end());
            bool canAssign = true;
            for(int i = mid - 1; i >= 0; --i) {
                auto it = prev(w.end());

                if(*it < tasks[i]) {
                    it = w.lower_bound(tasks[i] - strength);
                    if(it == w.end()) {
                        canAssign = false;
                        break;
                    }
                    ++p;
                    if(p > pills) {
                        canAssign = false;
                        break;
                    }
                }
                w.erase(it);
            }

            if(canAssign)
                left = mid ;
            else
                right = mid - 1;
        }
        return left;
    }
};