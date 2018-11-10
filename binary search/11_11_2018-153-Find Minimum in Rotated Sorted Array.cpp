class Solution {
public:
    int findMin(vector<int>& nums) {
        int len=nums.size();
        int i=0,j=len-1;
        if (len==0)
            return 0;
        if (len==2)
            return (nums[i]<nums[j])?nums[i]:nums[j];
        if (nums[0]<nums[len-1])
            return nums[0];  
        while(i+1<j)
        {
            int mid=(i+j)/2;
            if (nums[i]==nums[j] && nums[mid]==nums[i])
                {
                int min=nums[i];
                for (int t=i;t<=j;t++)
                    if (nums[t]<min)
                        min=nums[t];
                return min;
                }
            if (nums[mid]>=nums[i])
                i=mid;
            else
                j=mid;  
        }
       return nums[j];  
    }
};
