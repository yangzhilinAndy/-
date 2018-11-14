//Solution1: use heap to get top k frequent elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        for (auto ele: nums)
            freq[ele]++;
        
        priority_queue< int, vector<int>, greater<int> > topK;
      
        for (auto cnt: freq)
        {
            topK.push(cnt.second);
            while(topK.size()>k) topK.pop();
        }
      
        vector<int> ans;
        
        for (auto cnt: freq)
        {
         if (cnt.second>=topK.top())
             ans.push_back(cnt.first);
        }
            
        return ans;
    }
};
