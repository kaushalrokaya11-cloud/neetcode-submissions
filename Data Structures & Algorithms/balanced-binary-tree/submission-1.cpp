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

    bool isBalanced(TreeNode* root) {
    if(heightFinder(root)==-1){return false;}
    return true;
   
        
    }

    int heightFinder(TreeNode* root){
        if(root==nullptr){return 0;}

        int leftnodeHeight=heightFinder(root->left);
        if(leftnodeHeight==-1){return -1;}
        int rightnodeHeight=heightFinder(root->right);
        if(rightnodeHeight==-1){return -1;}

        int diff=abs(leftnodeHeight-rightnodeHeight);
        if(diff>1){
            return -1;
        }
        return 1+max(leftnodeHeight,rightnodeHeight);

    }
};
