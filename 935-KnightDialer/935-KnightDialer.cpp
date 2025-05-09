// Last updated: 5/9/2025, 2:00:23 PM
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string repeated = word;

        while (sequence.find(repeated) != string::npos) {
            repeated += word;
            k++;
        }

        return k;
    }
};