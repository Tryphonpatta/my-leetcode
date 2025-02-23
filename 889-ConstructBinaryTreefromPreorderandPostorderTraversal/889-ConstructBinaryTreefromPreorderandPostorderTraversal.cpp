/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int j = 0;
        stack<TreeNode*> st;
        TreeNode* root;
        for (int i = 0; i < preorder.size(); i++) {
            TreeNode* newNode = new TreeNode(preorder[i]);
            if (st.size() == 0) {
                st.push(newNode);
                root = newNode;
                continue;
            }
            TreeNode* pre = st.top();
            st.push(newNode);
            if (pre->left == NULL) {
                pre->left = newNode;
            } else {
                pre->right = newNode;
            }
            while (!st.empty() && postorder[j] == st.top() -> val) {
                st.pop();
                j++;
            }
        }
        return root;
    }
};