class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if (len==0)
            return 0;
        if (len==1)
            return nums[0];
        int* sum=new int [len];
        sum[0]=nums[0];
        sum[1]=max(nums[0],nums[1]);
        for (int i=2; i<len; i++)
            sum[i]=max(sum[i-1],sum[i-2]+nums[i]);
        return sum[len-1];
    }
};
