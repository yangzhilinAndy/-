class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    if (nums.empty())
            return 0;
    auto it1=nums.begin();
    auto it2=--nums.end();

     while (it1!=nums.end() && *it1!=val)
         it1++;
     if (it1==nums.end())
        return nums.size();
      
     while (it2!=nums.begin() && *it2==val) 
         it2--;
     if (it2==nums.begin() && *it2==val)
         return 0;
        
    while (it1<it2)
    {
        *it1=*(it2--);
        while (it1<it2 && *it1!=val)
        it1++;
        while (it1<it2 && *it2==val) 
        it2--;
    }
    
    //Beaware of this corner case!!! 
    //it2 should always point to the last non-val element 
    //unless it1<it2: it points to a val right after that non-val 
   
    if (*it2==val) 
        return it2-nums.begin(); 
        
    return it2-nums.begin()+1;
    }
};
