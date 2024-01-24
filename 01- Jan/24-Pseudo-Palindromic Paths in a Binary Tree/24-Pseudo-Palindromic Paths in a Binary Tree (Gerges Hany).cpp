
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
    int ans = 0; // number of pseudo-palindromic paths
    void count(vector < int >& mp, TreeNode *root){ 
      if (!root) return;
      mp[root->val]++;
      if (!root->left && !root->right){
        int odd = 0;
        for (int i = 0; i < 10; i++) odd += mp[i] & 1;
        ans += odd < 2;
      }
      count(mp, root->left);
      count(mp, root->right);
      mp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
      vector < int > mp(10);
      count(mp, root);
      return ans;
    }
};
