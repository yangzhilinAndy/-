/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //solution 1: Use recursion
 
 class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
        int leftmax=maxDepth(root->left);
        int rightmax=maxDepth(root->right);
        int max=(leftmax>rightmax)?leftmax:rightmax;
        return max+1;
    }
};
 
 
 //solution 2: Use bfs and count the maximum depth
class Solution {
public:
    int max=0;
    int maxDepth(TreeNode* root) {
        if (root==NULL)
            return 0;
       queue<TreeNode*> cur;
        cur.push(root);
        while(true)
        {
        queue<TreeNode*> next;   
        while(!cur.empty())
            {
            TreeNode* head=cur.front();
            cur.pop();
            if (head->left)
            next.push(head->left);
            if (head->right)
            next.push(head->right);
            }
        cur=next;
        max++;
        if (next.empty())
            break;
        }
        return max;
    }
};
