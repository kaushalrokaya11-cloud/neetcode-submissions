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
    int goodNodes(TreeNode* root) {
        if(!root){return 0;}
        int greatest=root->val;
        totalGoodNodes(root, greatest);
        return total;
        
    }

    void totalGoodNodes(TreeNode* node, int greatest){
        if(node->val>=greatest){
        total++;
        greatest=node->val;}
        
        if(node->left){totalGoodNodes(node->left,greatest);}
        if(node->right){totalGoodNodes(node->right,greatest);}

     

    }
};
