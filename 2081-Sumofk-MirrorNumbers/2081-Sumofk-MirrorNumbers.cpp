// Last updated: 6/23/2025, 10:32:48 AM
class Solution {
public:
    long long createPalindrome(long long n, bool odd){
        long long x = n;
        if (odd) x/= 10;
        while(x > 0){
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n;
    }
    long long check(long long num, int base){
        long long  reverse = 0;
        long long temp = num;
        while(num > 0) {
            reverse *= base;
            reverse += num % base;
            num /= base;
        }
        // cout << base << " " << reverse << " " << temp << endl;
        return reverse == temp;
    }
    long long kMirror(int k, int n) {
        long long ans = 0;
        for(int len = 1; n > 0; len *= 10 ){
            for(int i = len; i < len * 10 && n > 0 ;i ++){
                long long p = createPalindrome(i, true);
                // cout << p << endl;
                if(check(p, k)){
                    n --;
                    ans += p;
                }
            }
            for(int i = len; i < len * 10 && n > 0 ;i ++){
                long long p = createPalindrome(i, false);
                // cout << p << endl;
                if(check(p, k)){
                    n --;
                    ans += p;
                }
            }
        }
        return ans;
    }
};