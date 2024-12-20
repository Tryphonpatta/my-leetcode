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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int level = 0;
        while(!q.empty()){
            if(level % 2 != 0){
                vector<TreeNode*> v;
                vector<int> val;
                while(!q.empty() && q.front().second == level){
                    TreeNode* node = q.front().first;
                    v.push_back(q.front().first);
                    val.push_back(node->val);
                    q.pop();
                    if(node -> left)
                        q.push({node -> left,level + 1});
                    if(node -> right)
                        q.push({node -> right,level + 1});
                }
                for(int i = 0 ; i < v.size() ; i++){
                    v[i] -> val = val[val.size() - i - 1];
                }
            }
            else {
                while(!q.empty() && q.front().second == level){
                    TreeNode* node = q.front().first;
                    q.pop();
                    if(node -> left)
                        q.push({node -> left,level + 1});
                    if(node -> right)
                        q.push({node -> right,level + 1});
                }
            }
            level ++;
        }
        return root;
    }
};