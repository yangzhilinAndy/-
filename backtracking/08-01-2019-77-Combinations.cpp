class Solution {
public:
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    int i=0;
    vector<int> res(k,0);
    while(i>=0)
    {
     res[i]++;
    if (res[i]>n)
        i--;
    else if (i==k-1)
        ans.push_back(res); //base case of recursion
    else{
        i++;
        res[i]=res[i-1]; //recursion here
        }
    }
    return ans;
    }

        
};
