class Solution {
public:
    string longestPalindrome(string s) {
        unsigned int len=s.length(), start=0, currlen=0;
        int maxlen=0;
        char ans[2000];
        
        //palindrome is odd in length
        for (int cent=0;cent<len;cent++)
        {
            currlen=1;
            int off;
            for (off=1; cent-off>=0 && cent+off<len; off++)
                if (s[cent+off]==s[cent-off])
                    currlen+=2;
                else
                    break;
            if (currlen>=maxlen)
            {
                maxlen=currlen;
                start=cent-off+1;
            }  
        }
       
        
        //palindrome is even in length           
        for (int cent=1; cent<len; cent++)
        {
            currlen=0;
            int off;
            for (off=1; cent-off>=0 && cent+off-1<len; off++)
                if (s[cent-off]==s[cent+off-1])
                   currlen+=2;
                else
                    break;
            if (currlen>=maxlen)
                {
                start=cent-off+1;
                maxlen=currlen;
                }
        }
        
            
        int i=start;
        for (int j=0; j<maxlen; j++)
            ans[j]=s[i++];
        ans[maxlen]=0;
        return ans;
    }
};
