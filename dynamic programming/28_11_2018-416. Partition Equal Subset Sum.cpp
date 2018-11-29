//0-1 knapsack problem
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        if (n<2)
            return false;
        for (int i=0; i<n; i++)
            sum+=nums[i];
        if (sum%2!=0) return false;  //Be careful about this corner case!!!
        sum/=2;
        
        bool prev[20000],cur[20000];
        memset(prev,0,sizeof(prev));
        prev[0]=true;
        for (int i=0; i<n; i++)
        {
         for (int j=0; j<=sum; j++)
             if (j>=nums[i])
                cur[j]=prev[j]||prev[j-nums[i]];
             else
                cur[j]=prev[j];
         for (int j=0; j<=sum; j++)
            prev[j]=cur[j];
        }
        return cur[sum];
    }
};
