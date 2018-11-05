int BS(int l, int r, int* A, int* B, int c, int n, int m)
{
    int i=(l+r)/2,j=c-i;
    printf("%d",j);
    if (l<=r)
    {  
    if (i>0&&A[i-1]>B[j])
        return BS(l,i-1,A,B,c,n,m);
    if (j>0&&B[j-1]>A[i])
        return BS(i+1,r,A,B,c,n,m);
    }
    return i;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int m=nums1Size,n=nums2Size,c=(m+n+1)/2,i,j;
    if (m > n) 
    { 
    int* temp = nums1; nums1 = nums2; nums2 = temp;
    int tmp = m; m = n; n = tmp;
    }
    
    i=BS(0,m,nums1,nums2,c,n,m);
    j=c-i;
    //printf("%d",i);
    
    double med;
    int maxLeft=0;
    if (i == 0) 
        maxLeft = nums2[j-1];
    else if (j == 0) 
        maxLeft = nums1[i-1];
    else 
        maxLeft = nums1[i-1]>nums2[j-1]?nums1[i-1]:nums2[j-1]; 
        if ( (m + n) % 2 == 1 ) 
        return maxLeft;

        int minRight = 0;
        if (i == m) 
            minRight = nums2[j]; 
        else if (j == n) 
            minRight = nums1[i];
        else 
            minRight = nums2[j]<nums1[i]?nums2[j]:nums1[i]; 

        return (maxLeft + minRight) / 2.0;
    
    return med;    
}
