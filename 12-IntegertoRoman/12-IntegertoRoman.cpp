class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int nums = num;
        while (nums > 0) {
            if (nums >= 1000) {
                nums -= 1000;
                ans += 'M';
            }
            else if(nums >= 900){
                nums -= 900;
                ans += "CM";
            }
            else if(nums >= 500){
                nums -= 500;
                ans += 'D';
            }
            else if(nums >= 400){
                nums -=400;
                ans += "CD";
            }
            else if(nums >= 100){
                nums -= 100;
                ans += 'C';
            }
            else if(nums >= 90){
                nums -= 90;
                ans += "XC";
            }
            else if(nums >= 50){
                nums -= 50;
                ans += 'L';
            }
            else if(nums >= 40){
                nums -= 40;
                ans += "XL";
            }
            else if(nums >= 10){
                nums -= 10;
                ans += 'X';
            }
            else if(nums >= 9){
                nums -= 9;
                ans += "IX";
            }
            else if(nums >= 5){
                nums -= 5;
                ans += "V";
            }
            else if(nums >= 4){
                nums -=4;
                ans += "IV";
            }
            else if(nums >= 1){
                nums -= 1;
                ans += "I";
            }
        }
        return ans;
    }
};