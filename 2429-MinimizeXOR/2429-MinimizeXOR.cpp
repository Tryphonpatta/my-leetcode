class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0;
        while(num2 > 0){
            cnt += num2 & 1;
            num2 = num2 >> 1;
        }
        int temp = num1;
        int cnt1 = 0;
        while (temp > 0){
            cnt1 += temp & 1;
            temp = temp >> 1;
        }
        if(cnt1 == cnt)return num1;
        if (cnt1 > cnt){
            int x = 1;
            while(cnt1 > cnt){
                if(num1 & x){
                    num1 -= x;
                    cnt1 --;
                }
                x = x << 1;
            }
        }
        else {
            int x = 1;
            while(cnt1 < cnt){

                if((num1 & x) == 0){
                    num1 += x;
                    cnt1 += 1;
                }
                x = x * 2;
            }
        }
        return num1;
    }
};