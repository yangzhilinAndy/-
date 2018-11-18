//Consider the value of root and recursion
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root==NULL)
            return root;
        TreeNode* lroot, *rroot;
        lroot=trimBST(root->left, L, R);
        rroot=trimBST(root->right, L, R);
        if (root->val<L)
            return rroot;
        if (root->val>R)
            return lroot;
        root->left=lroot;
        root->right=rroot;
        return root;
    }
};
