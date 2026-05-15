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
int total=0;
    int diameterOfBinaryTree(TreeNode* root) {

        dfs(root);
        return total-1;
        
    }
    int dfs(TreeNode * root){
        if(!root) return 0;

        int leftHeight= dfs(root->left);
        int rightHeight= dfs(root->right);

        total= max(total,1+leftHeight+rightHeight);

        return max(1+leftHeight,1+rightHeight);
    }
};
