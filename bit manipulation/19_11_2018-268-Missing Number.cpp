//Solution 1: use XOR, idea from https://leetcode.com/problems/missing-number/solution/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),miss=n;
        for (int i=0; i<n; i++)
            miss^=nums[i]^i;
        return miss;
    }
};

//Solution 2: Use Gauss formula to compute the sum and subtract all the numbers
