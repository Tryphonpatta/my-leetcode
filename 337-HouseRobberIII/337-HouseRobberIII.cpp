// Last updated: 5/9/2025, 12:20:23 PM
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
    unordered_map<TreeNode*,int> dp;
    int rob(TreeNode* root) {
        if(root == NULL)return 0;
        if(dp.count(root))return dp[root];
        int select = 0 ;
        if(root -> left){
            select += rob(root -> left -> right) + rob(root -> left -> left);
        }
        if(root -> right) {
            select += rob(root -> right -> right) + rob(root -> right -> left);
        }
        return dp[root] =  max(root -> val + select, rob(root -> left) + rob(root->right));
    }
};