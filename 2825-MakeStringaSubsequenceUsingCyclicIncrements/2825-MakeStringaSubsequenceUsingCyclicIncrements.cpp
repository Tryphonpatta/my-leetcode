class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int index = 0;
        for(int i = 0 ; i < str1.size() ; i++){
            if(index < str2.size() && ((str1[i] - 'a' + 1) % 26 == (str2[index] -'a') % 26 || str1[i] == str2[index])){
                index ++;
            }
        }
        return index == str2.size() ? true : false;
    }
};