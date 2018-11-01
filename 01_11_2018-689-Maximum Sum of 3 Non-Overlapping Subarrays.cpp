/**

If we fix the middle subarray, then the problem is reduced to finding one maximal subarray in the range before and after this middle subarray, which could be solved in linear time. And there are O(n) number of possible middle subarrays.

*/


class Solution {
public:
    int mySum(vector<int>& nums, int beg, int k)
    {
        int sum=0;
        for (int i=beg; i<beg+k; i++)
            sum+=nums[i];
        return sum;
    }
    
    int oneSubArr(vector<int>& nums, int beg, int end, int k)
    {
        int sum,ans=beg,max;
        sum=mySum(nums, beg, k);
        max=sum;
        for (int j=beg+1; j+k-1<=end; j++)
        {
            sum=sum-nums[j-1]+nums[j+k-1];
            if (max<sum)
            {
                max=sum;
                ans=j;
            }
        }
        return ans;
    }
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int l,r,m;
        vector<int> ans;
        int maxsum=0;
        for (int mid=k; mid+k-1<nums.size()-k; mid++)
        {
            int left, right, all;
            left=oneSubArr(nums, 0, mid-1, k);
            right=oneSubArr(nums, mid+k, nums.size()-1, k);
            all=mySum(nums, left, k)+mySum(nums, mid, k)+mySum(nums, right, k);
            if (all>maxsum)
            {
                maxsum=all;
                l=left;
                r=right;
                m=mid;
            }
        }
        ans.push_back(l);
        ans.push_back(m);
        ans.push_back(r);
       
        return ans;
    }
};
