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

    int dfs(TreeNode* root){
        if(!root) return 0;

        depth++;
        total= max(total,depth);
        dfs(root->left);
        
        dfs(root->right);
        depth--;

        return 0;

    }
};
