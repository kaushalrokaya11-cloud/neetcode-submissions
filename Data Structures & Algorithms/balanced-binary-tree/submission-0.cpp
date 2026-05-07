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
    bool balanced=true;

    bool isBalanced(TreeNode* root) {
    heightFinder(root);
    return balanced;
        
    }

    int heightFinder(TreeNode* root){
        if(root==nullptr){return 0;}

        int leftnodeHeight=heightFinder(root->left);
        int rightnodeHeight=heightFinder(root->right);

        int diff=abs(leftnodeHeight-rightnodeHeight);
        if(diff>1){
            balanced=false;
        }
        return 1+max(leftnodeHeight,rightnodeHeight);

    }
};
