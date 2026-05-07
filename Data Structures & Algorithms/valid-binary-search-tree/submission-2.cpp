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
    bool isValidBST(TreeNode* root) {
        if(!root){return false;}

       return validityChecker(root,-1000,1000);
        
    }
    bool validityChecker(TreeNode* node,int leftB,int rightB)
    {
        if(!node){return true;}
        if(node->val<=leftB || node->val>=rightB ){
            return false;
        }

        // if( !node->left && !node->right){return true;}

        // if((node->left && node-> right) && (node->left->val>=node->val|| node->right->val<=node->val)){
        //     return false;
        // }
       
        return (validityChecker(node->left,leftB,node->val) && validityChecker(node->right,node->val,rightB));

    }
};
