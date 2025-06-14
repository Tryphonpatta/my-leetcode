// Last updated: 6/15/2025, 2:41:36 AM
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int first = s[0];
        int first_for_max = s[0];
        int i = 0;
        while(i < s.size() && s[i] == '9'){
            i ++;
        }
        if(i < s.size())first_for_max = s[i];
        int max = 0;
        string temp1,temp2;
        for(int i = 0; i < s.size() ; i++){
            if(s[i]== first_for_max) {
                temp1 += '9';
            }
            else temp1 += s[i];
        }
        for(int i = 0; i < s.size() ; i++){
            if(s[i]== first) {
                temp2 += '0';
            }
            else temp2 += s[i];
        }
        // cout << temp1 << endl;
        // cout << temp2;
        return stoi(temp1) - stoi(temp2);
    }
};