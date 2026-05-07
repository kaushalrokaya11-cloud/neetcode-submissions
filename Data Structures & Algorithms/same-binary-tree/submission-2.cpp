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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q!=nullptr||q==nullptr&&p!=nullptr){return false;}
        else if(p==nullptr && q==nullptr){cout<<"both null trees";return true;}

        queue <TreeNode*> q1,q2;
        q1.push(p);
        q2.push(q);


        while(!q1.empty() && !q2.empty()){
            if(q1.size()!=q2.size()){cout<<"size mismatch";return false;}
            int size=q1.size();
            for(int i=0;i<size;i++)
            {

            TreeNode* q1Node= q1.front();
            TreeNode* q2Node= q2.front();
            q1.pop();
            q2.pop();
            cout<<q1Node->val<<" "<<q2Node->val;
            if(q1Node->val!=q2Node->val){cout<<"value mismatch";return false;}
            
            if(q1Node->left!=nullptr && q2Node->left==nullptr||q1Node->left==nullptr&&q2Node->left!=nullptr)
            {cout<<"one node has left subtree and other doesnt"; return false;}

            if(q1Node->left!=nullptr){q1.push(q1Node->left);}
            if(q2Node->left!=nullptr){q2.push(q2Node->left);}


            if(q1Node->right!=nullptr && q2Node->right==nullptr||q1Node->right==nullptr&&q2Node->right!=nullptr)
            {cout<<"one node has left subtree and other doesnt";return false;}

            if(q1Node->right!=nullptr){q1.push(q1Node->right);}
            if(q2Node->right!=nullptr){q2.push(q2Node->right);}
            }

        }
        if(q1.empty() && q2.empty()){return true;}
        return false;
        
    }
};
