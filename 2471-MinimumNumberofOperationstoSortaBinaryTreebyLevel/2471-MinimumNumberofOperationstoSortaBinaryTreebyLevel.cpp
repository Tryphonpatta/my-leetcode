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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int d[100001] = {};
        int ans = 0;
        q.push(root);
        while (!q.empty()) {
            vector<int> v,w;
            int qs = q.size();
            int p[100001] = {};
            for (int i = 0; i < qs; i++) {
                TreeNode* x = q.front();
                q.pop();
                v.push_back(x -> val);
                w.push_back(x -> val);
                p[x -> val] = w.size() - 1;
                if(x -> left)q.push(x -> left);
                if(x -> right)q.push(x -> right);
            }
            sort(v.begin(),v.end());
            for(int i = 0 ; i < v.size() ; i++){
                d[v[i]] = i;
            }
            for(int i = 0 ; i < w.size() ; i++){
                // for(int j = 0; j < w.size();j++){
                //     cout << w[j] << " ";
                // }
                // cout << endl;
                if(v[i] != w[i]){
                    // cout << w[i] << " " << v[i] << " " << d[w[i]] << " " << p[v[i]] << endl;
                    int temp = w[i];
                    w[i] = v[i];
                    w[p[v[i]]] = temp;
                    p[temp] = p[v[i]];
                    ans ++;
                }
                // for(int j = 0; j < w.size();j++){
                //     cout << w[j] << " ";
                // }
                // cout << endl;
            }
        }
        return ans;
    }
};