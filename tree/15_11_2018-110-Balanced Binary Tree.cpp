/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //Solution 1: Strictly follows the definition of balanced binary tree with the help of a depth function
 //For each node in the tree, dfs on its left and right child: time complexity :O(N^2). This is a top down approach.
 
 class Solution {
public:
    int getHeight(TreeNode* root)
    {
        if (root==NULL)
            return 0;
        int l,r,h;
        l=getHeight(root->left);
        r=getHeight(root->right);
        h=(l<r)?r:l;
        h++;
        return h;
    }
    bool isBalanced(TreeNode* root) {
        if (root==NULL)
            return true;
       bool lis,ris,is=true;
       lis=isBalanced(root->left);
       ris=isBalanced(root->right);
       int l,r;
       l=getHeight(root->left);
       r=getHeight(root->right);
       if (l>r+1 || r>l+1)
           is=false;
       return (lis && ris && is);
    }
};

//Solution 2: Make full use of the DFS function, not only calculate height, but also return -1 to indicate unbalanceness
//If unbalance, no need to calculate further
class Solution {
public:
    int dfs(TreeNode* root)
    {
       if (root==NULL)
          return 0;
       int l,r,h;
       l=dfs(root->left);
       r=dfs(root->right);
       if (l<0 || r<0)
           return -1;
       if (l>r+1 || r>l+1)
           return -1;
        h=(l>r)?l:r;
        return h+1;
    }
    bool isBalanced(TreeNode* root) {
        if (root==NULL)
            return true;
       return dfs(root)>0;
    }
};
