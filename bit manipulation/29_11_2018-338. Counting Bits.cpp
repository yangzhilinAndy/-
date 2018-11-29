//Use a bit manipulation trick

class Solution {
public:
    vector<int> sol;
    vector<int> countBits(int num) {
        sol.push_back(0);
        for (int n=1; n<=num; n++)
            sol.push_back(sol[n/2]+n%2);
        return sol;
    }
};
