/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//non-recursive version
class Solution {
public:
    void flatten(TreeNode* root) {
      TreeNode* ptr1=root, *ptr2;
      while(ptr1)
        {
        ptr2=ptr1->left;
        if (ptr2)
        {
        while(ptr2->right)
            ptr2=ptr2->right;
        ptr2->right=ptr1->right;
        ptr1->right=ptr1->left;
        ptr1->left=NULL;
        }
        ptr1=ptr1->right;
        }
    }
};
