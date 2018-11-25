/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //At first attempt, I created a local object as new node of the new tree, but this object cannot exist 
 beyond this function! So we should instead modify one of two existed node
 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1==NULL && t2==NULL)
            return NULL;
        if (t1!=NULL && t2==NULL)
            return t1;
        if (t1==NULL && t2!=NULL)
            return t2;
        
        t1->left=mergeTrees(t1->left, t2->left);
        t1->right=mergeTrees(t1->right, t2->right);
        t1->val+=t2->val;
        return t1;
    }
};
