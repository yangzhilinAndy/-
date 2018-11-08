/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
//Main idea: a modification of BFS: use a stack to reverse the order of a level
 
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode *> st;
        vector<vector<int>> ans={};
        int order=-1;
        
        if (root==NULL) //Corner case
            return ans;
      
        st.push(root);
        
        while(true)
        {
        vector<int> level;
        vector<TreeNode *> cur;
        while(!st.empty())
        {
            TreeNode *node=st.top();
            cur.push_back(node);
            if (node)
            level.push_back(node->val);
            st.pop(); 
        }
        if (!level.empty()) //Corner case!!!!!!!!!
        ans.push_back(level);
        if (order==-1)
        for (TreeNode *node : cur)
        {
            if (node)
            {
            st.push(node->left);
            st.push(node->right);
            }
        }
        else
        for (TreeNode *node : cur)
        {
            if (node)
            {
            st.push(node->right);
            st.push(node->left);
            }
        }
        order*=-1;
        if (st.empty())
            break;
        }
        
        return ans;
    }
};
