// Beaware of many corner cases!!!

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length()==0)
            return 0;
        int dp[50000]={0}, maxlen=0;
        for (int i=1; i<s.length(); i++)
        {
            if (s[i]=='(')
                dp[i]=0;
            else if (s[i-1]=='(')
            {
                if (i-2>=0)
                    dp[i]=dp[i-2]+2;
                else
                    dp[i]=2;
            }
            else if (i-dp[i-1]-1<0)
                dp[i]=0;
            else if (s[i-dp[i-1]-1]=='(')
            {
                if (i-dp[i-1]-2>=0)
                    dp[i]=2+dp[i-1]+dp[i-dp[i-1]-2]; 
                else
                    dp[i]=2+dp[i-1];
            }
        }
        for (int i=1; i<s.length(); i++)
            if (dp[i]>maxlen)
                maxlen=dp[i];
        return maxlen;
    }
};
