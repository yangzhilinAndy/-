//Remark for myself: This problem is not hard, but I failed the submission many times
//Should be repracticed more times

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
    int longest=0;
    int longestRootPath(TreeNode* root)
    {
        if (root==NULL)
            return 0;
        
        int rtPathL=0,rtPathR=0;
        int longestPathl = longestRootPath(root->left);
        if (root->left!=NULL && (root->left)->val==root->val)
            rtPathL+=longestPathl+1;
        
        int longestPathr = longestRootPath(root->right);
        if(root->right!=NULL && (root->right)->val==root->val)
            rtPathR+=longestPathr+1;
        
        if (rtPathL+rtPathR>longest)
            longest=rtPathL+rtPathR;
        
        return max(rtPathR,rtPathL);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if (root==NULL)
            return 0;
        longestRootPath(root);
        
        return longest;
    }
};
