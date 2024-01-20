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
   int dfs(TreeNode* root, int mx = 0, int mn = 1e9){
       if (!root) return mx - mn;
       mx = max(mx, root -> val);
       mn = min(mn, root -> val);
       return max(dfs(root -> left), dfs(root -> right));
   }

public:
    int maxAncestorDiff(TreeNode* root) {
       return dfs(root);
    }
};
