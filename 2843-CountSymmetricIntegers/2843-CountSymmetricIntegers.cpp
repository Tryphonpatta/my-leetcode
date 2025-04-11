// Last updated: 4/12/2025, 1:32:13 AM
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low ; i <= high ; i++){
            string s = to_string(i);
            if(s.size() % 2 != 0)continue;
            int first = 0;
            int last = 0;
            for(int j = 0 ; j < s.size() / 2 ; j++){
                // cout << "first : " << s[j] - '0' << endl;
                // cout << "second : " << s[j + s.size() / 2] << endl; 
                first += s[j] - '0';
                last += s[j + s.size()/2] - '0';
            }
            // cout << i << " " << first << " " << last << endl;
            if(first == last)ans ++;
        }
        return ans;
    }
};