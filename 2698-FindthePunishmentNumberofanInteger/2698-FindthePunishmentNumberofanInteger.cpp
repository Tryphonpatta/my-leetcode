class Solution {
public:
    bool rec(string stringNum, int target) {
        if (stringNum == "" && target == 0) return true;

        if (target < 0) return false;
        for (int i = 0; i < stringNum.size(); i++) {
            string left = stringNum.substr(0, i + 1);
            string right = stringNum.substr(i + 1);
            int leftNum = stoi(left);
            if (rec(right, target - leftNum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int currentNum = 1; currentNum <= n; currentNum++) {
            int squareNum = currentNum * currentNum;
            if (rec(to_string(squareNum), currentNum)) {
                ans += squareNum;
            }
        }
        return ans;
    }
};