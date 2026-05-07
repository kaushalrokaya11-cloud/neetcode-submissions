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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        int longestedge=0;
        depth(root,diameter);
        return diameter;
       
    }

    int depth(TreeNode *root,int &diameter){
        if(root==nullptr){
            return 0;
        }
       int  leftedge=depth(root->left,diameter);
        int rightedge=depth(root->right,diameter);

        diameter=max(diameter,leftedge+rightedge);
        return 1+max(leftedge,rightedge);
    }
};
