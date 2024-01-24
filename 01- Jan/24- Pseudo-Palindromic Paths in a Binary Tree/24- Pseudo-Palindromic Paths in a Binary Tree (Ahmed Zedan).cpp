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

// author : Ahmed Zedan


// explain : 
/*
    - solution approach (dfs)
    - need dfs to move in each path in tree
    - to know numbers in path can plindrom or not can use (xor) betwise operator 
    - why xor ? (x^x = 0) so frequency element (x) 
    if even xor all this frequency is 0 
    if od xor all this frequency is x
    - we get power of 2 for all element in tree to be unique bit 
    - in the end of path if mask (power of 2) or equal (0) that mean can be exist plindrom permutation
    - (x & (x-1)) = 0 that mean x is power of 2
*/

class Solution {
public:
    int dfs(TreeNode* root , int mask = 0){
        if(!root) return 0 ; 

        mask ^= (1<<root->val) ; 

        
        if(!root->left && !root->right){
            return ((mask & mask-1)==0) ; 
        }

        return dfs(root->left , mask) + dfs(root->right , mask) ; 
    }

    int pseudoPalindromicPaths (TreeNode* root , int vis = 0) {
        return dfs(root) ;

    }
};