// Last updated: 5/2/2025, 9:08:40 AM
class Solution {
public:
    string pushDominoes(string dominoes) {
        int a[100002] = {};
        int diff = 0;
        for(int i = 0; i < dominoes.size() ;i++){
            if(dominoes[i] == '.'){
                a[i] += diff;
                if(diff > 0)diff --;
            }
            else if (dominoes[i] == 'R'){
                diff = 100001;
            }
            else if(dominoes[i] == 'L'){
                diff = 0;
            }
        }
        for(int i = dominoes.size() - 1; i >= 0 ;i--){
            if(dominoes[i] == '.'){
                a[i] += diff;
                if(diff < 0)diff ++;
            }
            else if (dominoes[i] == 'R'){
                diff = 0;
            }
            else if(dominoes[i] == 'L'){
                diff = -100001;
            }
        }
        string ans = "";
        for(int i = 0; i < dominoes.size() ; i++){
            if(dominoes[i] == 'L' || dominoes[i] == 'R')ans += dominoes[i];
            else if(a[i] > 0) ans += 'R';
            else if(a[i] < 0) ans += 'L';
            else ans += '.';
        }
        return ans;
    }
};