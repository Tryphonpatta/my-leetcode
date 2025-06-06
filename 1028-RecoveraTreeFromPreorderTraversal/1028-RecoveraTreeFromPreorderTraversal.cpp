/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> stack;
        int index = 0;
        while(index < traversal.size()) {
            int depth = 0;
            while(index < traversal.size() && traversal[index] == '-'){
                depth ++;
                index ++;
            }

            int value = 0;
            while(index < traversal.size() && traversal[index] <= '9' && traversal[index] >= '0'){
                value = value * 10 + traversal[index] - '0';
                index ++;
            }

            TreeNode* node = new TreeNode(value);

            while(stack.size() > depth){
                stack.pop();
            }
            if(!stack.empty()){
                if(stack.top() -> left == NULL){
                    stack.top() -> left = node;
                }
                else {
                    stack.top() -> right = node;
                }
            }
            stack.push(node);    
        }
        while(stack.size() > 1)stack.pop();
        return stack.top();
    }
};