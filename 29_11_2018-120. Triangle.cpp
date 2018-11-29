class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev(n,0);
        vector<int> cur(n,0);
        if (n==0 || triangle[0].size()==0)
            return 0;
         if (n==1)
            return triangle[0][0];
        for (int i=0; i<n; i++)
            prev[i]=triangle[n-1][i];
        for (int row=n-2; row>=0; row--)
        {
            for (int i=0; i<=row; i++)
                cur[i]=min(prev[i],prev[i+1])+triangle[row][i];
            for (int i=0; i<=row; i++)
                prev[i]=cur[i];
        }
         return cur[0];     
    }
};
