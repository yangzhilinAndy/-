bool canJump(int* nums, int numsSize) {
  if (numsSize==1)
      return true;
  for (int i=0;i<numsSize-1;i++)
    if (nums[i]==0)
    {   
        int len=0,k;
        for (k=i-1;k>=0;k--)
        {   len++;
            if (nums[k]>len)
               break;
        }
        if (nums[k]<=len)
            return false;
    }
  
  if (nums[numsSize-1]==0)
    {   
        int len=0,k;
        for (k=numsSize-2;k>=0;k--)
        {   len++;
            if (nums[k]>=len)
               break;
        }
        if (nums[k]<len)
            return false;
    }
    return true;
}
