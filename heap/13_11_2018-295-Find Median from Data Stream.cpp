//The solution ideas credits to the solution in: https://leetcode.com/problems/find-median-from-data-stream/solution/
//solution 1: Use two heaps:

class MedianFinder {
private:
    priority_queue<double, vector<double>, less<double>> low_max;
    priority_queue<double, vector<double>, greater<double>> hi_min;
    
public:
    /** initialize your data structure here. */
    MedianFinder()=default;
    
    void addNum(int num) {
        low_max.push(num);
        
        hi_min.push(low_max.top()); 
        //Because probably this element is supposed to lie in the high_min heap rather than the low one. This step can correct mistakes.
        low_max.pop();
        
        if (low_max.size()<hi_min.size())
            {
            low_max.push(hi_min.top());
            hi_min.pop();
            }
    }
    
    double findMedian() {
        if (low_max.size()==hi_min.size())
            return (low_max.top()+hi_min.top())/2;
        else
            return low_max.top();
            
    }
};

//Solution 2: Use multiset to simulate self-balancing binary search tree
class MedianFinder {
private:
    multiset<double> BST;
    multiset<double>::iterator low,high;
public:
    /** initialize your data structure here. */
    MedianFinder():low(BST.end()),high(BST.end()){   
    }
    
    void addNum(int num) {
       if (BST.size()==0)
       {
           low=BST.insert(num);
           high=low;
       }
        else if (BST.size()%2!=0)
        {
        BST.insert(num);
        if (num<*low)
            low--;
        else
            high++;          
        }
        else
        {
        BST.insert(num);
        if (num<*low)
            high--;
        else if(num>=*high)
            low++; 
        else
        {
            high--;
            low++;
        }
        }
            
    }
    
    double findMedian() {
        return (*low+*high)/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
