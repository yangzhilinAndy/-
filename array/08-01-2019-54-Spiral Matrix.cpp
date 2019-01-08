class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        if (m==0)
            return ans;
        int n=matrix[0].size();
        if (n==0)
            return ans;
        int all=m*n, cnt=0, cur=0;
        //good method to implement clockwise walk:
        int dr[4]={0,1,0,-1}; 
        int dc[4]={1,0,-1,0};
        int r=0, c=0;
        bool **visited=new bool*[m];
        for (int j=0; j<m; j++)
        {
            visited[j]=new bool[n];
            memset(visited[j], 0, sizeof(bool)*n);
        }
        
        while(cnt<all){
            ans.push_back(matrix[r][c]);
            visited[r][c]=true;
            r=r+dr[cur];
            c=c+dc[cur];
            cnt++; 
            if (r==-1 || r==m || c==-1 || c==n || visited[r][c])
            {
                r=r-dr[cur];
                c=c-dc[cur];
                cur=(cur+1)%4;
                r=r+dr[cur];
                c=c+dc[cur];
            }
        }
            return ans;
    }
};


