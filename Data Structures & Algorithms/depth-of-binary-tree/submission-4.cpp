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
int depth=0;
int total=0;
    int maxDepth(TreeNode* root) {
        
        dfs(root);
        return total;
        
    }

    void dfs(TreeNode* root){
        if(!root) return ;

        depth++;
        total= max(total,depth);
        dfs(root->left);
        
        dfs(root->right);
        depth--;

        

    }
};
