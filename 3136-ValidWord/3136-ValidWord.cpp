// Last updated: 7/15/2025, 8:57:24 AM
class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)return false;
        //check sign
        for(int i=0;i < word.size();i++){
            if((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || 
                (word[i] >= '0' && word[i] <= '9')
            )
                continue;
            else return false;
        }
        bool vowel[200] = {};
        vowel['a'] = vowel['A'] = 1;
        vowel['e'] = vowel['E'] = 1;
        vowel['i'] = vowel['I'] = 1;
        vowel['o'] = vowel['O'] = 1;
        vowel['u'] = vowel['U'] = 1;
        int cntVowel = 0;
        int cntConsonant = 0;
        for(auto w : word) {
            if((w >= 'a' && w <= 'z') || (w >= 'A' && w <= 'Z') ){
                if(vowel[w])cntVowel ++;
                else cntConsonant ++;
            }
        }
        return cntVowel && cntConsonant;
    }
};