/*approach 1: divide and conquer
There are other approaches such as Horizontal scanning, Vertical scanning and Binary search.
Solution idea source: https://leetcode.com/problems/longest-common-prefix/solution/
*/

class Solution {
public:
    string findCommonPrefix(string str1, string str2)
    {
        int cnt=0;
        int len=(str1.length()<str2.length())?str1.length():str2.length();
        for (cnt=0;cnt<len;cnt++)
            if (str1[cnt]!=str2[cnt])
                break;
        string pref(str1, 0, cnt);
        return pref;  
    }
    
    string PrefixInRange(int beg, int end, vector<string>& strs)
    {
        string prefix,left,right;
        int mid=(beg+end)/2;
        if (beg==end)
            return strs[beg];
        if (beg+1==end)
            return findCommonPrefix(strs[beg], strs[end]);
        left=PrefixInRange(beg, mid, strs);
        right=PrefixInRange(mid+1, end, strs);
        prefix=findCommonPrefix(left, right);
        return prefix;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
     int size=strs.size();
     if (size==0)
         return "";
     for (string str : strs)
        if (str.length()==0)
            return "";
      string prefix=PrefixInRange(0, size-1, strs);
      return prefix;
    }
};
