/*Solution idea: from https://leetcode.com/problems/minimum-height-trees/discuss/178356/CPP-Multiple-Solutions
use BFS from leaves to root, a little like topological sort
*/

class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> cur;
        vector<unordered_set<int> > neighbor(n); 
        //good use of data structure: for adjacency list, nodes are labeled, but neighbours can be unordered 
        for (auto pa : edges)
        {
            neighbor[pa.first].insert(pa.second);
            neighbor[pa.second].insert(pa.first);
        }
       if (n==1) //Beaware of this corner case!!!!!! (The node 0 won't appear in edge list)
       {
           cur.push_back(0);
           return cur; 
       }
        
       for (int i=0; i<n; i++)
           if (neighbor[i].size()==1)
               cur.push_back(i);

       while(true)
       {
          vector<int> next;
          for (int leaf : cur)
            for (int j:neighbor[leaf])
                {
                 neighbor[j].erase(leaf); 
                 if (neighbor[j].size()==1)
                    next.push_back(j);
                } 
          if (next.empty())
              return cur;
           cur=next;
       }
          
    }

};
