class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int isVowel[200] = {};
        isVowel['a'] = 1;
        isVowel['e'] = 1;
        isVowel['i'] = 1;
        isVowel['o'] = 1;
        isVowel['u'] = 1;
        unordered_map<char,int> vowelCount;
        long long ans = 0;
        int left = 0, right = 0;
        int notVowel = 0;
        int countVowel= 0;
        vector<int> nextConsonant(word.size());
        int nextConsonantIndex = word.size();
        for (int i = word.size() - 1; i >= 0; i--) {
            nextConsonant[i] = nextConsonantIndex;
            if (!isVowel[word[i]]) {
                nextConsonantIndex = i;
            }
        }
        map<char, int> m;
        while (left <= right && right < word.size()) {
            if(isVowel[word[right]]){
                vowelCount[word[right]]++;
            }
            else {
                notVowel ++;
            }
            while( notVowel > k) {
                if(isVowel[word[left]]){
                    vowelCount[word[left]] --;
                    if (vowelCount[word[left]] == 0)
                        vowelCount.erase(word[left]);
                }
                else notVowel --;
                left ++;
            }
            while (left < word.size() && vowelCount.size() == 5 && notVowel == k){
                ans += nextConsonant[right] - right;
                if(isVowel[word[left]]) {
                    vowelCount[word[left]] --;
                    if(vowelCount[word[left]] == 0)
                        vowelCount.erase(word[left]);
                }
                else notVowel --;
                left ++;
            }
            right ++;
        }
        
        return ans;
    }
};