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
int diameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        int longestedge=0;
        depth(root);
        return diameter;
       
    }

    int depth(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
       int  leftedge=depth(root->left);
        int rightedge=depth(root->right);

        diameter=max(diameter,leftedge+rightedge);
        return 1+max(leftedge,rightedge);
    }
};
