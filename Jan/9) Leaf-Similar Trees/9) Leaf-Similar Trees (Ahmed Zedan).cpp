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

class Solution {
public:
    void getLeaves(vector<int>&leaf , TreeNode* root){
        if(!root) return ; 
        if(!root->left && !root->right) leaf.push_back(root->val) ; 
        getLeaves(leaf , root->left) ; 
        getLeaves(leaf , root->right) ; 
    } 

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> leaf1 , leaf2 ; 
        getLeaves(leaf1 , root1) ; 
        getLeaves(leaf2 , root2) ; 
        return leaf1 == leaf2 ; 
    }
};