// author : Ahmed Zedan

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

 /*
    - max difference = max value of tree - min value of tree
 */
class Solution {
public:
    int rec(TreeNode* r , int mx = INT_MIN , int mn = INT_MAX){
        if(!r) return mx - mn ;
        mx = max(mx,r->val) ;
        mn = min(mn,r->val) ;
        return max(rec(r->left,mx,mn) ,rec(r->right,mx,mn)) ;
    }
    int maxAncestorDiff(TreeNode* root) {
        return rec(root) ;
    }
};