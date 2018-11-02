class Solution {
public:
    int dp[50000], temp[50000];
    int numDistinct(string s, string t) {
        if (t.length()==0)
            return 1;
        memset(dp,0,sizeof(dp));
        memset(temp,0,sizeof(temp));
        if (s[0]==t[0])
        {
            dp[0]=1;
            temp[0]=1;
        }
        for (int i=1; i<s.length(); i++)
        {
            for (int j=0; j<=i; j++)
                {
                    if (s[i]==t[j] && j>0)
                        dp[j]+=temp[j-1];
                    else if (s[i]==t[j] && j==0)
                        dp[j]+=1;
                }
            memcpy(temp,dp,sizeof(temp));
        }
        return dp[t.length()-1];             
    }
};
