class Solution {
public:
    vector<int> minOperations(string boxes) {
        int a = boxes[boxes.size() - 1] - '0';
        int b = boxes[0] - '0';
        int k;
        vector<int> answer = vector<int>(boxes.size(), 0);
        // Forward pass
        for (k = 1; k < boxes.size(); k++) {
            answer[k] = answer[k - 1] + b;
            if (boxes[k] == '1') {
                b++;
            }
        }
        // Backward pass
        b = boxes[boxes.size() - 1] - '0';
        for (k = boxes.size() - 2; k >= 0; k--) {
            answer[k] += b;
            if (boxes[k] == '1') {
                a++;
            }
            b += a;
        }
        return answer;
    }
};