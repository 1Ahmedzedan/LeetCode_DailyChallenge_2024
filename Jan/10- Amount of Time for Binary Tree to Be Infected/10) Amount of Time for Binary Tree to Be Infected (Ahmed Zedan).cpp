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
    1) we need get parent node to each node in tree (by dfs)
    2) we need to get start node (by dfs)
    3) we need to get number of levels when start node is tree root (by bfs)
    4) number of minutes = number of level - 1
 */
 
class Solution {
public:
    // to get parent to each node
    void getAdjNode(TreeNode* root , map<TreeNode* , TreeNode*> &adj){
        if(!root) return ;
        adj[root->left] = root ; 
        adj[root->right] = root ;
        getAdjNode(root->left , adj) ; 
        getAdjNode(root->right , adj) ; 
    }

    // to get start node 
    void findStartNode(TreeNode* root , int startVal , TreeNode* &startNode){
        if(!root) return ; 
        if(root->val == startVal){
            startNode = root ; 
            return ; 
        } 

        findStartNode(root->left , startVal , startNode) ;  
        findStartNode(root->right , startVal , startNode) ;   
    }

    // to get number of levels when start node is tree root
    int countTreeLevelFromStartNode(TreeNode* startNode , map<TreeNode* , TreeNode*> &adj){
        int lvl = 0 ; 
        map<TreeNode* , int>vis ; 
        queue<TreeNode*> bfs ; 
        bfs.push(startNode) ;
        vis[startNode] = 1 ;  
        while(!bfs.empty()){
            int n = bfs.size();
            lvl ++ ; 
            while(n--){
                auto curr = bfs.front() ; 
                vis[curr] = 1 ;
                bfs.pop() ; 
                if(curr->left!=nullptr && !vis[curr->left]){
                    bfs.push(curr->left) ;
                    vis[curr->left] = 1 ; 
                } 
                if(curr->right!=nullptr && !vis[curr->right]){
                    bfs.push(curr->right) ;
                    vis[curr->right] = 1 ; 
                }
                if(adj[curr]!=nullptr && !vis[adj[curr]]){
                    bfs.push(adj[curr]) ; 
                    vis[adj[curr]] = 1 ; 
                }
            }
        }
        return lvl ; 
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode* , TreeNode*> adj ;
        getAdjNode(root , adj) ; 
        TreeNode* startNode = nullptr ; 
        findStartNode(root , start , startNode) ; 
        int time = countTreeLevelFromStartNode(startNode , adj) - 1; 
        return time  ;
    }
};