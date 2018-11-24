//Use two hash table because this should be a bijection mapping
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len=s.size();
        unordered_map<char, char> h1, h2; 
        for (int i=0; i<len; i++)
            if (h1.count(s[i])==0)
                h1[s[i]]=t[i];
            else if (h1[s[i]]!=t[i])
                    return false;
        
        for (int i=0; i<len; i++)
            if (h2.count(t[i])==0)
                h2[t[i]]=s[i];
            else if (h2[t[i]]!=s[i])
                    return false;
        
        return true;
    }
};
