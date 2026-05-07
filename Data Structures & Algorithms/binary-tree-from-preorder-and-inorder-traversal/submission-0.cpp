/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    TreeNode* build(
        vector<int>& preorder,
        int& preIndex,
        int inLeft,
        int inRight,
        unordered_map<int, int>& inorderIndex
    ) {
        if (inLeft > inRight) {
            return nullptr;
        }

        int rootValue = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(rootValue);

        int mid = inorderIndex[rootValue];

        root->left = build(preorder, preIndex, inLeft, mid - 1, inorderIndex);
        root->right = build(preorder, preIndex, mid + 1, inRight, inorderIndex);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;

        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int preIndex = 0;

        return build(preorder, preIndex, 0, inorder.size() - 1, inorderIndex);
    }
};