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
    int h[100001];
    int ans[100001];
    int findHeight(TreeNode *root){
        if(root == NULL)return 0;
        h[root -> val] = max(findHeight(root->left),findHeight(root->right)) + 1;
        return h[root->val];
    }
    int returnHeight(TreeNode *node)
    {
        if(node == NULL)return -1;
        return h[node -> val];
    }
    int findAns(TreeNode *root,int depth,int m)
    {
        if(root == NULL)return 0;
        ans[root -> val] = max(depth,m + 1);
        findAns(root ->left, depth + 1, max(m,depth + returnHeight(root -> right)));
        findAns(root ->right, depth + 1, max(m,depth + returnHeight(root -> left)));
        return 0;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root);
        findAns(root,0,0);
        vector<int> a;
        for(int i = 0; i < queries.size() ;i++)
        {
            // cout << h[queries[i]] << " ";
            a.push_back(ans[queries[i]] - 1);
        }
        return a;
    }
};