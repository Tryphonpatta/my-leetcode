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
class FindElements {
public:
    unordered_map<int,int> m;
    FindElements(TreeNode* root) {
        rec(root, 0);
    }
    int rec(TreeNode* root,int x) {
        if(root == NULL)return 0;
        m[x] = 1;
        rec(root -> left, 2 *x + 1);
        rec(root -> right,2 *x + 2);
        return 0;
    } 
    
    bool find(int target) {
        if(m[target])return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */