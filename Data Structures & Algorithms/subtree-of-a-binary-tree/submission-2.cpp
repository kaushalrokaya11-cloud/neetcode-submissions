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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if(!root){return false;}

        if(isIdentical(root,subRoot)){
            return true;
        }
        if(root){
            return(isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot));
        }
        else {return false;}
        
    }
    bool isIdentical(TreeNode*root,TreeNode*subroot){
        if(!root && !subroot){return true;}

        if(root && subroot && root->val==subroot->val){
            return isIdentical(root->left,subroot->left)&& isIdentical(root->right,subroot->right);
        }
        else{
            return false;
        }

    }
};
