class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        int prev=nums[0]; //Record the 1st num to avoid duplicate
        for (auto j=nums.begin(); j<nums.end(); j++)
        {
            while (j>nums.begin() && j<nums.end() && *j==prev)
                j++;
            if (j>=nums.end())
                break;
            auto i1=j+1,i2=nums.end();
            i2--;
            while(i1<i2)
            {
                if (*j+*i1+*i2<0)
                    i1++;
                else if (*j+*i1+*i2>0)
                    i2--;
                else
                {
                    vector<int> ans;
                    ans.push_back(*j);
                    ans.push_back(*i1);
                    ans.push_back(*i2);
                    res.push_back(ans);
                    int has=*i1;
                    while (i1>nums.begin() && i1<nums.end() && *i1==has)
                        i1++; //Record the second num to avoid duplicate
                }
            }
            prev=*j;
        }
         return res;   
    }
};
