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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n==0)
            return res;
        return generate(1, n);
    }
    
    vector<TreeNode*> generate(int beg, int end){
        vector<TreeNode*> res,ltrees,rtrees;
        if (beg>end)
        {
            res.push_back(NULL);
            return res;
        }
        for (int x=beg; x<=end; x++)
        {
            ltrees=generate(beg, x-1);
            rtrees=generate(x+1, end);
            for (TreeNode* l : ltrees)
                for (TreeNode* r : rtrees)
                {
                    TreeNode* node=new TreeNode(x); //here! We must use new to create node
                    node->left=l;
                    node->right=r;
                    res.push_back(node);
                }      
        }
        return res;
        
    }
};
