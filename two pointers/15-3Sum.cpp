class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<3)
            return res;
        sort(nums.begin(),nums.end());
        for (auto j=nums.begin(); j<nums.end(); j++)
        {
            while (j>nums.begin() && j<nums.end() && *j==*(j-1))
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
                    i1++;
                    while (i1>nums.begin() && i1<nums.end() && *i1==*(i1-1))
                        i1++;
                }
            }
        }
         return res;   
    }
};
