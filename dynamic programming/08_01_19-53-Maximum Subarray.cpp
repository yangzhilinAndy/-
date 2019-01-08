class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int len=nums.size();
       if (nums.empty())
           return 0;
        if (len==1)
            return nums[0];
        int *sum=new int[len];
        sum[0]=nums[0];
        for (int i=1; i<len; i++)
            sum[i]=max(sum[i-1]+nums[i],nums[i]);
        int maxSum=sum[0];
        for (int i=1; i<len; i++)
            maxSum=max(sum[i],maxSum);
        return maxSum;
    }
    
};
